# ultiMATE tester for your ft_containers

## Description
This script is used to test and compare different container implementations in the C++ programming language. It can be used to test the performance and functionality of various container types, such as vector, map, set, stack, and other. It also has options for checking for memory leaks and printing the diff of the test outputs.

## Usage
To use this script, make sure that it is executable by running the following command:
```
chmod +x script.sh
```

Then, you can run the script with the following format:
```
./script.sh [options] [container_type(s)] [unit_test_file]
```

### Options
- `-b`: Run in benchmark mode
- `-c`: Update the include path in the `common.cpp` file
- `-d`: Print the diff of the test outputs
- `-l`: Print the output and diff to the console
- `-h`: Print a help message
- `-z`: Check for memory leaks

### Container Types
You can specify one or more of the following container types to test:

- `vector`
- `map`
- `stack`
- `other`

If no container type is specified, the script will default to testing all of the above container types.

### Unit Test File
You can specify a unit test file in the format `*` to test the containers with. If no unit test file is specified, the script will use the default test cases.

## Example
To test the `vector` and `map` container types with the `clear.cpp` file, and print the diff of the test outputs, you can use the following command:
```
./script.sh -d vector map clear
```

## Logs
All errors and leaks are saved in the log directory.

## Contributions
All pull request are welcome, if you want to improve, or add some tests.

## Credits
Created by [B-Bischoff](https://github.com/B-Bischoff), 
[cybattis](https://github.com/cybattis), 
[mliboz](https://github.com/MaxenceLiboz), 
[Tarchimb](https://github.com/Tarchimb)
