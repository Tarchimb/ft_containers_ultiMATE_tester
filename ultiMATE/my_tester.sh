#!/bin/bash

RED="\033[1;31m";
GREEN="\033[1;32m";
END="\033[1;0m";

# $1 = $@
declare_variables ()
{
	LOGS_FOLDER="logs"
	std="0" ft="1" flags="-Werror"
	diff_success="true" compilation_ft_error="false" compilation_std_error="false"
	
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

# -d : Print diff if any
# -p : Print ouput programs
# -l : Print logs compilation
# -m : Compile with multiple 
main ()
{
	print_title
	# trap end_program SIGINT
	declare_variables "$@"
	containers=(vector) # map stack set)
	unit_files=$(echo $* | grep -o "\w*.cpp\w*")
	
	if [ "$unit_files" != "" ]
	then
		unit_function "$containers" "$unit_files"
	else
		for container in ${containers[@]}
		do
			update_container_path $container
			test_files=$(find "$container" -type f -name '*.cpp' | sort)
			for file in ${test_files[@]}
			do
				filename=$(echo $file | cut -c$(echo ${container}/ | wc -c)- | sed 's/.cpp//g')
				run "${filename}" "${file}" &
			done
		done
	fi
	wait
	find $LOGS_FOLDER/ -empty -type d -delete
	rm *.txt &>/dev/null
}

print_title ()
{
	echo -e $GREEN
	printf '%b\n' "$(cat title/title.txt)"
	echo -e $END
}

# $1 = container; $2 = (filename).cpp
unit_function()
{
	filenames=($2)
	for file in ${filenames[@]}
	do
		filename=$(echo $file | sed 's/.cpp//g')
		path="$1/$file"
		run "${filename}" "${path}"
	done
}

# $1 = container_name
update_container_path ()
{
	old_include_name="$(cat common.cpp | grep \"vector.hpp\")"
	if [ "$old_include_name" == "" ]
	then
		return;
	fi
	path="$(find ~ -name vector.hpp -print -quit)" &>/dev/null
	include_name="$(cat common.cpp | grep vector.hpp)"
	if [[ "$include_name" == *"$path"* ]]
	then
		return
	fi
	sed -i '' "s|${include_name}|#include \"${path}\"|" common.cpp
}

# $1 = filename; $2 = container/file.cpp;
run ()
{
	mkdir -p $LOGS_FOLDER/$1
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
		echo -e "${RED}ft_${1}: Compilation error$END"
		compilation_ft_error="true"
		return
	fi
	c++ "$flags" -o "std_$1" "-DNAMESPACE=$std" "$2" &>$redir
	if [ $? -eq 1 ]
	then
		rm "ft_$1"
		echo -e "${RED}std_${1}: Compilation error$END"
		compilation_std_error="true"
		return
	fi
}

# $1 = filename
execute ()
{
	./ft_$1 &>$redir
	./std_$1 &>$redir
}

diff_outfiles() 
{
	mutex
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
			echo -en "$index"$GREEN" OK" $END
			rm $std_file  &>/dev/null
			rm $ft_file  &>/dev/null
		else # Move failed tests logs into logs folder
			echo -en "$index"$RED" NOT OK" $END
			mv $std_file "$LOGS_FOLDER/$filename/"
			mv $ft_file "$LOGS_FOLDER/$filename/"
		fi

		index=$((index+1));
		check_if_file_exists $index;
	done

	clean_path
	echo
	rm -rf /tmp/mylock &>/dev/null
}

mutex ()
{
	if mkdir /tmp/mylock &>/dev/null
	then
		echo -en $filename:
	else
  		mutex
	fi
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
	rm *.txt 2&>/dev/null
	rm ft* 2&>/dev/null
	rm std* 2&>/dev/null
	rm -rf $LOGS_FOLDER/* &>/dev/null
	exit
}

main "$@"