#!/bin/bash

RED="\033[1;31m";
GREEN="\033[1;32m";
END="\033[1;0m";

declare_variables ()
{
	ft_flag="-D FT=1"
	std_flag="-D FT=0"

	int_type="-D TYPE=int"
	unsigned_char_type="-D TYPE=unsigned char"
	string_type="-D TYPE=std::string"
	float_type="-D TYPE=float"

	integer_value_type="-D VALUE_TYPE=42"
	string_value_type="-D VALUE_TYPE=\"42\""
	float_value_type="-D VALUE_TYPE=4.2"

	new_integer_value_type="-D NEW_VALUE=420"
	new_string_value_type="-D NEW_VALUE=\"420\""
	new_float_value_type="-D NEW_VALUE=4.20"
	

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

	if echo $* | grep -e "-m" -q
	then
		multiple_value_test="true"
	else
		multiple_value_test="false"
	fi

	if echo $* | grep -e "-p" -q
	then
		print_output="true"
	else
		print_output="false"
	fi

	logs="logs"
	diff_success="true"
	compilation_error="false"
	execution_error="false"
}

# $1 = filename; $2 = file.cpp; $3 = TYPE; $4 = VALUE_TYPE; $5 = NEW_VALUE
run ()
{
	compile "$1" "$2" "$3" "$4" "$5" 2&>$redir
	if [ "$compilation_error" == "true" ]
	then
		echo -en "$RED" "Compilation error $END"
		exit
	fi
	execute "$1" 2&>$redir
	if [ "$execution_error" == "true" ]
	then
		echo -en "$RED" "Execution error $END"
		exit
	fi
	difference "$1"
	delete_output "$1"
}

# $1 = filename; $2 = file.cpp; $3 = TYPE; $4 = VALUE_TYPE;
compile ()
{
	c++ -o "ft_$1" "$ft_flag" "$3" "$4" "$5" "$2"
	if [ $? -eq 1 ]
	then
		compilation_error="true"
	fi
	c++ -o "std_$1" "$std_flag" "$3" "$4" "$5" "$2"
}

# $1 = filename
execute ()
{
	./ft_$1 > ft_$1.txt
	if [ $? -eq 1 ]
	then
		execution_error="true"
	fi
	./std_$1 > std_$1.txt
	if [ "$print_output" == "true" ]
	then
		echo ========================================
		./ft_$1
		echo ========================================
		./std_$1
	fi
}

# $1 = filename
difference()
{
	if [ "$print_diff" == "true" ]
	then
		git --no-pager diff --text --no-index ft_$1.txt std_$1.txt
	fi
	git --no-pager diff --text --no-index ft_$1.txt std_$1.txt &> diff_$1.txt
	if [ $? -eq 1 ]
	then
		echo -en "$1: $RED NOT OK$END\n"
		diff_success="false"
		delete_output "$1" 2&>$redir
	fi
}

# $1 = filename
delete_output ()
{
	if [ "$diff_success" == "true" ]
	then
		rm *$1* 
		cd $logs
		rm *$1* 2&>/dev/null
		cd ..
	else
		mv *.txt "$logs/"
		rm "ft_$1" "std_$1" 
		exit
	fi
}

# $1 = filename
prints()
{
	if [ $diff_success == "true" ]
	then
		echo -en "$1: $GREEN OK$END\n"
	fi
}

# $1 = filename; $2 = file.cpp
launch_with_different_types()
{
	run "$1"  "$2" "$int_type" "$integer_value_type" "$new_integer_value_type"
	if [ "$multiple_value_test" == "true" ]
	then
		run "$1" "$2" "$char_type" "$integer_value_type" "$new_integer_value_type"
		run "$1" "$2" "$string_type" "$string_value_type" "$new_string_value_type"
		run "$1" "$2" "$float_type" "$float_value_type" "$new_float_value_type"
	fi
	prints "$1"
}

# $1 = container; $2 = (filename).cpp
single_function()
{
	filenames=($2)
	for file in ${filenames[@]}
	do
		filename=$(echo $file | sed 's/.cpp//g')
		path="$1/$file"
		launch_with_different_types "${filename}" "${path}"
	done
}

# -d : Print diff if any
# -p : Print ouput programs
# -l : Print logs compilation
# -m : Compile with multiple 
main ()
{
	declare_variables "$@"
	containers=(vector) # map stack set)
	single_file=$(echo $* | grep -o "\w*.cpp\w*")
	
	if [ "$single_file" != "" ]
	then
		single_function "$containers" "$single_file"
	else
		for container in ${containers[@]}
		do
			test_files=$(find "$container" -type f -name '*.cpp' | sort)
			for file in ${test_files[@]}
			do
				filename=$(echo $file | cut -c$(echo ${container}/ | wc -c)- | sed 's/.cpp//g')
				launch_with_different_types "${filename}" "${file}"
			done
		done
	fi
}

main "$@"