#!/bin/bash

VERSION=0.2

# CONFIGURATION
# =============================================================================
SRCS_PATH=.

LOGS_FOLDER="logs"
STD="0"
FT="1"
FLAGS="-Werror"
DIFF_SUCCESS="true"
COMP_ERROR_FT="false"
COMP_ERROR_STD="false"
TESTER_PATH="$(find "$(pwd)" -d -name ft_containers_ultiMATE_tester -type d -print -quit)"

stty -echoctl

init_script ()
{
    PRINT_DIFF="false"
    REDIR="/dev/null"
    LEAKS=""
    CONTAINERS=()
    UNIT_FILE=""

    if [ "$(cat ${TESTER_PATH}/common.cpp | grep $HOME)" == "" ]; then
        init_include
    else
        echo -e "${YELLOW}Includes path already setup$END"
    fi
    parse_argument "$@"
    if [ -z "${CONTAINERS[0]}" ]; then
      CONTAINERS=(vector other)
    fi
}

init_include()
{
    echo -e "${YELLOW}Update include path...$END"

    if [ "$(pwd)" == "$TESTER_PATH" ]; then
        local abs_path="$( cd .. "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    else
        local abs_path=$(cd -- "$(dirname -- "")" && printf '%s\n' "$(pwd -P)/$(basename -- "")")
    fi
    find . -name "*.hpp" > tmp
    awk -v path=$abs_path '{ sub(/\.\//, path); print}' tmp > tmp1 && mv tmp1 tmp
    sed 's/\/Users/\t#include "\/Users/g' tmp > tmp1 && mv tmp1 tmp
    sed 's/$/"/g' tmp > tmp1 && mv tmp1 tmp
    ed -s ${TESTER_PATH}/common.cpp <<< $'27r tmp\nw'
    rm -f tmp

    echo -e "${YELLOW}Path updated!${END}"
}

parse_argument()
{
   OPTION=""
   while [ $1 ]; do
     case $1 in
       vector|map|set|stack|other)
          CONTAINERS+=($1);
          shift ;;
       *.cpp)
          UNIT_FILE=$1
          shift ;;
       *)
          OPTION="$OPTION $1"
          shift;;
     esac
   done
   # Parse option
   while getopts bdlhzc opt $OPTION; do
       case $opt in
         (b) echo -e "Benchmark mode";;
         (c) init_include;;
         (d) PRINT_DIFF="true";;
         (l) REDIR="/dev/stdout";;
         (h) print_help;;
         (z) init_leaks;;
         (\?) echo -e "Invalid option: -$OPTARG"; exit 1;;
       esac
     done
}

main ()
{
	print_title
	init_script "$@"
	trap end_program SIGINT &>/dev/null
	rm -rf ${TESTER_PATH}/$LOGS_FOLDER

	for container in "${CONTAINERS[@]}"
	do
        echo -e "==================================================================="
        echo -e "\t\t    Launching $container tests"
        echo -e "==================================================================="
		echo -e "${YELLOW}Start compiling... $END"
		if [ "$UNIT_FILE" != "" ]; then
			unit_function "$CONTAINERS" "$UNIT_FILE"
		else
			test_files=$(find "${TESTER_PATH}/${container}" -type f -name '*.cpp' | sort)
			for file in ${test_files[@]}
			do
				filename=$(echo $file | cut -c$(echo ${TESTER_PATH}/${container}/ | wc -c)- | sed 's/.cpp//g')
				run "${filename}" "${file}" &
			done
		fi
	  wait
	done
	wait
	find ${TESTER_PATH}/$LOGS_FOLDER/ -empty -type d -delete
	rm *.txt &>/dev/null
}

print_title ()
{
	echo -e $GREEN
	printf '%b\n' "$(cat ${TESTER_PATH}/title/title.txt)"
	echo -e $END
}

# $1 = container; $2 = (filename).cpp
unit_function()
{
	filenames=($2)
	for file in "${filenames[@]}"
	do
		filename=$(echo $file | sed 's/.cpp//g')
		path="${TESTER_PATH}/$1/$file"
		run "${filename}" "${path}"
	done
}

# $1 = filename; $2 = container/file.cpp;
run ()
{
#	 echo "$LOGS_FOLDER/$1"
#	 exit
	mkdir -p ${TESTER_PATH}/$LOGS_FOLDER/$1
	compile "$1" "$2" "$FT"
	if [ "$COMP_ERROR_FT" == "true" ] || [ "$COMP_ERROR_STD" == "true" ]; then
		COMP_ERROR_FT="false" COMP_ERROR_STD="false"
		return
	else
		execute $1
		diff_outfiles
	fi
}

# $1 = filename; $2 = container/file.cpp; $3 = $FT | $STD
compile ()
{
	c++ "$FLAGS" -o "ft_$1" "-DNAMESPACE=$FT" "$2" &>$REDIR
	if [ $? -eq 1 ]
	then
		mutex_lock
		echo -e "${RED}ft_$1: Compilation error$END"
		mutex_unlock
		COMP_ERROR_FT="true"
		return
	fi

	c++ "$FLAGS" -o "std_$1" "-DNAMESPACE=$STD" "$2" &>$REDIR
	if [ $? -eq 1 ]; then
		rm "ft_$1"
		mutex_lock
		echo -e "${RED}std_$1: Compilation error$END"
		mutex_unlock
		COMP_ERROR_STD="true"
		return
	fi
}

# $1 = filename
execute ()
{
	if [ -n "$LEAKS" ]; then
		$LEAKS ./ft_$1 &> "$filename"_ft_leaks.txt;
	else
		./ft_$1 &>$REDIR
	fi
	./std_$1 &>$REDIR
}

diff_outfiles()
{
	mutex_lock
	echo -en $filename:
	index=1
	check_if_file_exists $index

	if [ ! -z "$LEAKS" ]
	then
		check_leaks
	fi

	while (( "$?" == "0" ))
	do
		local std_file="$filename"_"$index""_std.txt"
		local ft_file="$filename"_"$index""_ft.txt"

		if [ "$PRINT_DIFF" == "true" ]
		then
			git --no-pager diff --text --no-index $ft_file $std_file
		fi
		git --no-pager diff --text --no-index $ft_file $std_file &>$REDIR

		if [ "$?" == "0" ]; then # Delete passed tests logs
			echo -en "$index"$GREEN" OK" $END
			rm $std_file  &>/dev/null
			rm $ft_file  &>/dev/null
		else # Move failed tests logs into logs folder
			echo -en "$index"$RED" NOT OK" $END
			mv $std_file "${TESTER_PATH}/$LOGS_FOLDER/$filename/"
			mv $ft_file "${TESTER_PATH}/$LOGS_FOLDER/$filename/"
		fi

		index=$((index+1));
		check_if_file_exists $index
	done

	rm "$filename"_ft_leaks.txt &>/dev/null

	clean_path
	echo
	mutex_unlock
}

mutex_lock ()
{
	if mkdir /tmp/mylock &>/dev/null
	then
		return
	else
		mutex_lock
	fi
}

mutex_unlock ()
{
	rm -rf /tmp/mylock &>/dev/null
}

check_if_file_exists()
{
	file_name="$filename"_"$1""_std.txt";
	`test -e $file_name`;
}

clean_path ()
{
	rm ft_$filename &>/dev/null
	rm std_$filename &>/dev/null
}

#Use to clean stop when SIGINT, but not really work for now
end_program ()
{
	echo -e "${YELLOW}Killing process...${END}"
	kill $(jobs -rp)
	wait $(jobs -rp) 2>/dev/null
	mutex_unlock
	echo -e "${YELLOW}Cleaning...${END}"
	sleep 2
	rm *.txt 2&>/dev/null
	rm ft* 2&>/dev/null
	rm std* 2&>/dev/null
	rm -rf ${tester_path}/$LOGS_FOLDER &>/dev/null
	echo -e "${YELLOW}Done!${END}"
	exit
}

check_leaks() {
	local leaks_file="$filename"_ft_leaks.txt;
	if [ "$OS" == "Linux" ]; then
		grep " 0 errors from 0 contexts " "$leaks_file" &> /dev/null;
	else
		grep " 0 LEAKS for 0 total leaked bytes." "$leaks_file" &> /dev/null;
	fi
	if [ "$?" == "0" ]; then
		echo -en $GREEN[Leaks OK] $END;
		rm $leaks_file;
	else
		echo -en $RED[Leaks NOT OK] $END;
		mv $leaks_file "${TESTER_PATH}/$LOGS_FOLDER/$filename/" &> /dev/null;
	fi
}

init_leaks() {
	OS=`uname`;
	if [ "$OS" == "Linux" ]; then
		init_leaks_linux;
	elif [ "$OS" == "Darwin" ]; then
		init_leaks_macos;
	else
		echo "This tester does not support LEAKS check on this OS";
	fi
}

init_leaks_linux () {
	valgrind --version &>/dev/null;
	if [ $? -eq 0 ]; then
		echo "Leaks check: ON";
		LEAKS="valgrind --leak-check=full";
	else
		echo "Valgrind not found, LEAKS check : OFF";
	fi
}

init_leaks_macos () {
	LEAKS -h &>/dev/null;
	if [ $? -eq 0 ]; then
		echo "Leaks check: ON";
		LEAKS="LEAKS -atExit -q -- ";
	else
		echo "Leaks command not found, LEAKS check : OFF";
	fi
}

print_help() {
  echo -e "${GREEN}ft_containers_ultiMATE_tester$END $VERSION"
  echo -e ""
  echo -e "${YELLOW}USAGE:$END ./my_script [option] [container] [unit_test]"
  echo -e "  - No [container] launch all tests."
  echo -e "  - No [unit_tests] launch all tests of the container."
  echo -e ""
  echo -e "${YELLOW}OPTIONS:$END"
  echo -e "    -b \t launch benchmark tests"
  echo -e "    -c \t relaunch initialization of include path"
  echo -e "    -d  \t Print the diff if any"
  echo -e "    -l  \t Print logs compilation"
  echo -e "    -h  \t help"
#  echo -e "    -m  \t Compile multiple unit tests"
#  echo -e "    -p  \t Print output programs"
  echo -e "    -z  \t launch tests for memory LEAKS"
  exit
}

RED="\033[1;31m"
GREEN="\033[1;32m"
END="\033[1;0m"
YELLOW="\033[0;33m"

main "$@"
