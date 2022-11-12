#!/bin/bash

RED="\033[1;31m";
GREEN="\033[1;32m";
END="\033[1;0m";

declare_variables ()
{
	LOGS_FOLDER="logs"
	std="0" ft="1" flags="-Werror"
	diff_success="true" compilation_error="false"
	
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

}

# $1 = filename; $2 = container/file.cpp;
run ()
{
	mkdir -p $LOGS_FOLDER/$1
	compile "$1" "$2" "$ft"
	if [ "$compilation_error" == "true" ]
	then
		compilation_error="false"
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
		echo -e "${RED}${1}: Compilation error$END"
		compilation_error="true"
		return
	fi
	c++ "$flags" -o "std_$1" "-DNAMESPACE=$std" "$2" &>$redir
}


# $1 = filename
execute ()
{
	./ft_$1 &>$redir
	./std_$1 &>$redir
}

diff_outfiles() 
{
	echo -en $filename: 
	index=1;
	check_if_file_exists $index;
	while (( "$?" == "0" ))
	do
		local std_file="$filename"_"$index""_std.txt"
		local ft_file="$filename"_"$index""_ft.txt"

		if [ "$print_diff" == "true" ]
		then
			git --no-pager diff --text --no-index $std_file $ft_file
		fi
		git --no-pager diff --text --no-index $std_file $ft_file &>$redir

		if [ "$?" == "0" ]
		then # Delete passed tests logs
			echo -en "$index"$GREEN" OK" $END;
			rm $std_file;
			rm $ft_file;
		else # Move failed tests logs into logs folder
			echo -en "$index"$RED" NOT OK" $END
			mv $std_file "$LOGS_FOLDER/$filename"
			mv $ft_file "$LOGS_FOLDER/$filename"
		fi

		index=$((index+1));
		check_if_file_exists $index;
	done

	clean_path
	echo
}

check_if_file_exists() 
{
	file_name="$filename"_"$1""_std.txt";
	`test -e $file_name`;
}

clean_path ()
{
	find $LOGS_FOLDER -empty -type d -delete
	rm ft_$filename
	rm std_$filename
}

# $1 = container; $2 = (filename).cpp
single_function()
{
	filenames=($2)
	for file in ${filenames[@]}
	do
		filename=$(echo $file | sed 's/.cpp//g')
		path="$1/$file"
		run "${filename}" "${path}"
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
				# echo file: $file
				filename=$(echo $file | cut -c$(echo ${container}/ | wc -c)- | sed 's/.cpp//g')
				run "${filename}" "${file}"
			done
		done
	fi
}

main "$@"