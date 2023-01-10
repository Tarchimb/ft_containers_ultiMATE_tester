#ifndef COMMON_CPP
#define COMMON_CPP
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

#define TEST_INIT() \
        change_ofs_to_next_test(ofs, testName);\
		ofs << "the following tests are from file: " << __FILE__ << std::endl;\
		ofs << "test on line: " << __LINE__ << std::endl; \

#define INIT_SIGNAL() \
        open_file(ofs, testName + "_" + std::to_string(test)); \
        signal(SIGSEGV, handler);  \
        signal(SIGABRT, handler);  \
        signal(SIGBUS, handler)

#ifndef NAMESPACE
# define NAMESPACE 0
#endif

#if NAMESPACE==0
	#define FILE_NAME "_std"
	#define CURRENT_NAMESPACE std
#else
	#define FILE_NAME "_ft"
	#define CURRENT_NAMESPACE ft
#endif

int test = 1; // Used to create indexed log


std::ofstream ofs;

void handler(int signum)
{
    ofs << (signum == SIGSEGV ? "SEGMENTATION FAULT" : signum == SIGABRT ? "ABORT" : "BUS ERROR") << std::endl;
    exit(1);
}

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

std::ostream& operator<<(std::ostream& o, const TestStruct& v) {
	o << v.a << " " << v.b << " " << v.c;
	return o;
}

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
}

void write_result(std::ofstream& ofs, const TestStruct& val)
{
	ofs << std::to_string(val) << std::endl;
}

#endif
