#!/bin/bash

RED="\033[1;31m"
GREEN="\033[1;32m"
END="\033[1;0m"
YELLOW="\033[0;33m"

SRCS_PATH=/Users/Cyril/Dev/42/ft_containers/srcs

# $1 = $@
declare_variables ()
{
	LOGS_FOLDER="logs"
	std="0" ft="1" flags="-Werror"
	diff_success="true" compilation_ft_error="false" compilation_std_error="false"
	NULL="&>/dev/null"
	tester_path="$(find . -name ultiMATE -type d -print -quit)"

	if echo $* | grep -e "-d" -q
	then
		print_diff="true"
	else
		print_diff="false"
	fi

	if echo $* | grep -e "-l" -q
	then
		redir="/dev/stdout"
	else
		redir="/dev/null"
	fi

	if echo $* | grep -e "-z" -q
	then
		init_leaks;
	else
		leaks=""
	fi
}

# -d : Print diff if any
# -p : Print ouput programs
# -l : Print logs compilation
# -m : Compile with multiple
main ()
{
	declare_variables "$@"
	print_title
	trap end_program SIGINT &>/dev/null
	rm -rf ${tester_path}/$LOGS_FOLDER
	containers=(lexicographical_compare vector) # map stack set)
	unit_files=$(echo $* | grep -o "\w*.cpp\w*")

	for container in "${containers[@]}"
	do
	  echo -e "==================================================================="
	  echo -e "Launching $container tests"
	  echo -e "==================================================================="
		update_container_path "$container"
		echo -e "${YELLOW}Start compiling... $END"
		if [ "$unit_files" != "" ]
		then
			unit_function "$containers" "$unit_files"
		else
			test_files=$(find "${tester_path}/${container}" -type f -name '*.cpp' | sort)
			for file in ${test_files[@]}
			do
				filename=$(echo $file | cut -c$(echo ${tester_path}/${container}/ | wc -c)- | sed 's/.cpp//g')
				run "${filename}" "${file}" &
			done
		fi
	  wait
	done
	wait
	find ${tester_path}/$LOGS_FOLDER/ -empty -type d -delete
	rm *.txt &>/dev/null
}

print_title ()
{
	echo -e $GREEN
	printf '%b\n' "$(cat ${tester_path}/title/title.txt)"
	echo -e $END
}

# $1 = container; $2 = (filename).cpp
unit_function()
{
	filenames=($2)
	for file in "${filenames[@]}"
	do
		filename=$(echo $file | sed 's/.cpp//g')
		path="${tester_path}/$1/$file"
		run "${filename}" "${path}"
	done
}

# $1 = container_name
update_container_path ()
{
	old_include_name="$(cat ${tester_path}/common.cpp | grep \"$1.hpp\")"
	if [ "$old_include_name" == "" ]
	then
		return;
	fi
	echo -e "${YELLOW}Searching for your $1 file ${END}"
	local container_path="$(find $SRCS_PATH -name $1.hpp -print -quit 2>/dev/null)"

	if test -z "$container_path"
	then
		echo -e "${YELLOW}$1.hpp not found. Please include manually in common.cpp${END}"
		exit
	fi

	include_name="$(cat ${tester_path}/common.cpp | grep $1.hpp)"
	sed -i '' "s|${include_name}|\t#include \"${container_path}\"|" ${tester_path}/common.cpp
	echo -e "${YELLOW}Updated $1 path with : ${container_path}${END}"
}

# $1 = filename; $2 = container/file.cpp;
run ()
{
#	 echo "$LOGS_FOLDER/$1"
#	 exit
	mkdir -p ${tester_path}/$LOGS_FOLDER/$1
	compile "$1" "$2" "$ft"
	if [ "$compilation_ft_error" == "true" ] || [ "$compilation_std_error" == "true" ]
	then
		compilation_ft_error="false" compilation_std_error="false"
		return
	else
		execute $1
		diff_outfiles
	fi
}

# $1 = filename; $2 = container/file.cpp; $3 = $ft | $std
compile ()
{
	c++ "$flags" -o "ft_$1" "-DNAMESPACE=$ft" "$2" &>$redir
	if [ $? -eq 1 ]
	then
		mutex_lock
		echo -e "${RED}ft_$1: Compilation error$END"
		mutex_unlock
		compilation_ft_error="true"
		return
	fi
	c++ "$flags" -o "std_$1" "-DNAMESPACE=$std" "$2" &>$redir
	if [ $? -eq 1 ]
	then

		rm "ft_$1"
		mutex_lock
		echo -e "${RED}std_$1: Compilation error$END"
		mutex_unlock
		compilation_std_error="true"
		return
	fi
}

# $1 = filename
execute ()
{
	if [ ! -z "$leaks" ]
	then
		$leaks ./ft_$1 &> "$filename"_ft_leaks.txt;
	else
		./ft_$1 &>$redir
	fi
	./std_$1 &>$redir
}

diff_outfiles()
{
	mutex_lock
	echo -en $filename:
	index=1
	check_if_file_exists $index

	if [ ! -z "$leaks" ]
	then
		check_leaks
	fi

	while (( "$?" == "0" ))
	do
		local std_file="$filename"_"$index""_std.txt"
		local ft_file="$filename"_"$index""_ft.txt"

		if [ "$print_diff" == "true" ]
		then
			git --no-pager diff --text --no-index $ft_file $std_file
		fi
		git --no-pager diff --text --no-index $ft_file $std_file &>$redir

		if [ "$?" == "0" ]
		then # Delete passed tests logs
			echo -en "$index"$GREEN" OK" $END
			rm $std_file  &>/dev/null
			rm $ft_file  &>/dev/null
		else # Move failed tests logs into logs folder
			echo -en "$index"$RED" NOT OK" $END
			mv $std_file "${tester_path}/$LOGS_FOLDER/$filename/"
			mv $ft_file "${tester_path}/$LOGS_FOLDER/$filename/"
		fi

		index=$((index+1));
		check_if_file_exists $index
	done

	rm "$filename"_ft_leaks.txt &> /dev/null

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
	kill $(jobs -p) 2&>/dev/null
	# rm *ft*.txt 2&>/dev/null
	# rm ft* 2&>/dev/null
	# rm std* 2&>/dev/null
	rm -rf ${tester_path}/$LOGS_FOLDER &>/dev/null
	exit
}

check_leaks() {
	local leaks_file="$filename"_ft_leaks.txt;
	if [ "$OS" == "Linux" ]
	then
		grep " 0 errors from 0 contexts " "$leaks_file" &> /dev/null;
	else
		grep " 0 leaks for 0 total leaked bytes." "$leaks_file" &> /dev/null;
	fi
	if [ "$?" == "0" ]
	then
		echo -en $GREEN[Leaks OK] $END;
		rm $leaks_file;
	else
		echo -en $RED[Leaks NOT OK] $END;
		mv $leaks_file "${tester_path}/$LOGS_FOLDER/$filename/" &> /dev/null;
	fi
}

init_leaks() {
	OS=`uname`;
	if [ "$OS" == "Linux" ]
	then
		init_leaks_linux;
	elif [ "$OS" == "Darwin" ]
	then
		init_leaks_macos;
	else
		echo "This tester does not support leaks check on this OS";
	fi
}

init_leaks_linux () {
	valgrind --version &>/dev/null;
	if [ $? -eq 0 ]
	then
		echo "Leaks check: ON";
		leaks="valgrind --leak-check=full";
	else
		echo "Valgrind not found, leaks check : OFF";
	fi
}

init_leaks_macos () {
	leaks -h &>/dev/null;
	if [ $? -eq 0 ]
	then
		echo "Leaks check: ON";
		leaks="leaks -atExit -q -- ";
	else
		echo "Leaks command not found, leaks check : OFF";
	fi
}

main "$@"
