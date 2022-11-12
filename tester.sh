#!/bin/bash

LOGS_FOLDER="logs";

std=0;
ft=1;

name="";
container="";

if [ "$1" == "-show" ]
then
	redir="/dev/stdout";
else
	redir="/dev/null";
fi

leaks="";

# COLORS
RED="\033[1;31m";
GREEN="\033[1;32m"
END="\033[1;0m";

compile () {
	local namespace=$1;
	target="$container/$name.cpp";

	g++ -o $name -DNAMESPACE=$namespace $target &>$redir;
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
	echo "Leaks: not implemented yet for MacOs";
}

start_program () {

	if [ $? -eq 0 ]
	then

		if [ "$1" == "$ft" ]
		then
			local namespace="ft";
		else
			local namespace="std";
		fi
		outfile="$name""_$namespace""_leaks.txt";

		$leaks ./$name &> $outfile;

		if [ "$?" != "0" ]
		then
			echo -en $RED "Program crashed" $END;
			rm $outfile;
			return;
		fi

		if [ ! -z "$leaks" ]
		then
			grep " 0 errors from 0 contexts " "$outfile" &> /dev/null;
			if [ "$?" == "0" ]
			then
				echo -en $GREEN[$namespace Leaks OK] $END;
				rm $outfile;
			else
				echo -en $RED[$namespace Leaks NOT OK] $END;
				mv $outfile "$LOGS_FOLDER/$name" &> /dev/null;
			fi
		fi

	else
		echo $name " from container: " $container " does not compile";
	fi
}

diff_outfiles() {
	index=1;
	check_if_file_exists $index;

	while (( "$?" == "0" ))
	do
		local std_file="$name"_"$index""_std.txt"
		local ft_file="$name"_"$index""_ft.txt"

		diff -U3 $std_file $ft_file &>$redir;
		if [ "$?" == "0" ]
		then # Delete passed tests logs
			echo -en "$index"$GREEN" OK" $END;
			rm $std_file;
			rm $ft_file;
		else # Move failed tests logs into logs folder
			echo -en "$index"$RED" NOT OK" $END;
			mv $std_file "$LOGS_FOLDER/$name" &> /dev/null;
			mv $ft_file "$LOGS_FOLDER/$name" &> /dev/null;
		fi

		index=$((index+1));
		check_if_file_exists $index;
	done

	echo ;
	rm $name; # delete binary file
}

check_if_file_exists() {
	file_name="$name"_"$1""_std.txt";
	`test -e $file_name`;
}

run_test () {
	name=$1;
	if [ "$name" == "" ]
	then
		return;
	fi

	mkdir -p $LOGS_FOLDER/$name;

	echo -n "$name: ";

	compile $ft;
	namespace=$ft;
	start_program $ft;
	compile $std;
	start_program $std;

	diff_outfiles;
}

# --------------------------

#init_leaks;

mkdir -p $LOGS_FOLDER;
find $LOGS_FOLDER -type f -name '*.txt' -delete;

container="vector";
run_test "iterator";
run_test "default_constructor";
run_test "value_constructor";
run_test "range_constructor";
run_test "copy_constructor";
run_test "operator_equal";
run_test "begin";
run_test "end";
run_test "rbegin";
run_test "rend";
run_test "reserve";
run_test "at";
run_test "front";
run_test "back";
run_test "data";
run_test "push_back";
run_test "pop_back";
run_test "clear";
run_test "insert";
run_test "resize";
run_test "erase";


