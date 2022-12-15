#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>

#define TEST_INIT(x) \
		change_ofs_to_next_test(ofs, testName);\
		ofs << "the following tests are from file: " << __FILE__ << std::endl;\
		ofs << "test on line: " << __LINE__ << std::endl;                     \
		FORK(x)

#ifndef NAMESPACE
# define NAMESPACE 0
#endif

#if NAMESPACE==0
	#define FILE_NAME "_std"
	#define CURRENT_NAMESPACE std
#else
	#define FILE_NAME "_ft"
	#define CURRENT_NAMESPACE ft
#include "/Users/tarchimb/42/ft_containers/includes/pair.hpp"
#include "/Users/tarchimb/42/ft_containers/includes/equal.hpp"
#include "/Users/tarchimb/42/ft_containers/includes/is_integral.hpp"
#include "/Users/tarchimb/42/ft_containers/includes/lexicographical_compare.hpp"
#include "/Users/tarchimb/42/ft_containers/includes/enable_if.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/vector.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/map/chooseConst.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/map/map.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/map/tree_iterator.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/map/reverse_bidirectional_iterator.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/map/Node.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/map/tree.hpp"
#include "/Users/tarchimb/42/ft_containers/containers/stack.hpp"
#include "/Users/tarchimb/42/ft_containers/iterators/random_access_iterator.hpp"
#include "/Users/tarchimb/42/ft_containers/iterators/reverse_random_access_iterator.hpp"
#include "/Users/tarchimb/42/ft_containers/iterators/iterator_traits.hpp"
#include "/Users/tarchimb/42/ft_containers/iterators/iterator.hpp"
	// INCLUDE PATH HERE
#endif

#define FORK(x) \
		int status; \
		pid_t w, c_pid = fork(); \
		if (c_pid == -1)  \
			exit(0);         \
		else if (c_pid > 0) { \
        w = waitpid(c_pid, &status, WUNTRACED | WCONTINUED); \
        if (w == -1) {  \
        perror("waitpid"); \
        exit(EXIT_FAILURE); \
        } \
         \
        if (WIFSIGNALED(status)) { \
        	write_result(ofs, "CRASH"); \
        }           \
        }\
        else

int test = 1; // Used to create indexed log
std::ofstream ofs;

/*
 * TestStruct is a custom struct used to test containers with non-primitive types
 *
 * TestStuct volontary uses an int ptr to test Allocator destructing
 * (otherwise causing leaks to the test)
*/
struct TestStruct {
	int a;
	float b;
	std::string c;
	int *ptr;

	TestStruct(): a(0), b(0), c(""), ptr(new int(5)) {}
	TestStruct(const TestStruct& src) : ptr(new int(5)) { *this = src; }
	TestStruct(const int& A, const float& B, const std::string& C)
		: a(A), b(B), c(C), ptr(new int(5)) {}
	~TestStruct() { delete ptr; }

	TestStruct& operator=(const TestStruct& rhs) {
		if (this == &rhs) return *this;
		a = rhs.a;
		b = rhs.b;
		c = rhs.c;
		return *this;
	}
	TestStruct operator*(const int& n) const {
		TestStruct tmp = *this;
		tmp.a *= n;
		tmp.b *= n;
		tmp.c += tmp.c;
		return tmp;
	}

	TestStruct operator++() {
		TestStruct tmp = *this;
		a = a + 1;
		b = b + 1;
		c = c + c;
		return tmp;
	}

	friend bool operator==(const TestStruct& lhs, const TestStruct& rhs) {
		return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
	}

	friend bool operator<(const TestStruct &lhs, const TestStruct &rhs) {
		if (lhs.a >= rhs.a)
			return false;
		return true;
	}
};

void open_file(std::ofstream& ofs, const std::string& name)
{
	std::string file_name;
	file_name += name;
	file_name += FILE_NAME;
	file_name += ".txt";
	ofs.open(file_name);

	if (!ofs.is_open())
		exit (1);
}

void change_ofs_to_next_test(std::ofstream& ofs, const std::string& str)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, str + "_" + std::to_string(test));
	test++;
}

std::ostream& operator<<(std::ostream& o, const TestStruct& v) {
	o << v.a << " " << v.b << " " << v.c;
	return o;
}

namespace std {
	std::string to_string(const TestStruct& v) {
		std::string str;
		str += std::to_string(v.a) + " | ";
		str += std::to_string(v.b) + " | ";
		str += v.c;
		return str;
	}

	std::string to_string(const std::string& str) {
		return str;
	}

	template <typename T>
	std::string to_string(const CURRENT_NAMESPACE::vector<T>& v) {
		std::string str;
		for (int i = 0; i < v.size(); i++)
			str += std::to_string(v[i]);
		return str;
	}

	template <class U, class T>
	std::string to_string(const CURRENT_NAMESPACE::pair<U, T>& p) {
		return (std::string(std::to_string(p.first) + " " + std::to_string(p.second)));
	}
}

// ADD PRINT BEGIN IF NOT EMPTY
// ADD ITERATOR VALIDITY
template <typename T>
void write_result(std::ofstream& ofs, const CURRENT_NAMESPACE::vector<T>& vector, const bool printContent=true) {
	ofs << "size: " + std::to_string(vector.size()) << std::endl;
	ofs << "capacity: " + std::to_string(vector.capacity()) << std::endl;
	ofs << "empty: " + std::to_string(vector.empty()) << std::endl;
	if (printContent)
		for (int i = 0; i < vector.size(); i++)
			ofs << std::to_string(vector[i]) << std::endl;
}

void write_result(std::ofstream& ofs, const TestStruct& val)
{
	ofs << std::to_string(val) << std::endl;
}

template <typename T>
void write_result(std::ofstream& ofs, const T& val)
{
	ofs << std::to_string(val) << std::endl;
}
