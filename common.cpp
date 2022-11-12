#include "../src/vector.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>

#ifndef NAMESPACE
# define NAMESPACE 0
#endif


#if NAMESPACE==0
	using namespace std;
	#define FILE_NAME "_std"
#else
	using namespace ft;
	#define FILE_NAME "_ft"
#endif

struct TestStruct {
	int a;
	float b;
	std::string c;

	TestStruct(): a(0), b(0), c("") {}
	TestStruct(const TestStruct& src) { *this = src; }
	TestStruct(const int& A, const float& B, const std::string& C)
		: a(A), b(B), c(C) {}
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
};

std::ostream& operator<<(std::ostream& o, const TestStruct& v) {
	o << v.a << " " << v.b << " " << v.c;
	return o;
}

namespace std{
	std::string to_string(const TestStruct& v) {
		std::string str;
		str += std::to_string(v.a) + " | ";
		str += std::to_string(v.b) + " | ";
		str += v.c;
		return str;
	}
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

// ADD PRINT BEGIN IF NOT EMPTY
// ADD ITERATOR VALIDITY
template <typename T>
void write_result(std::ofstream& ofs, const vector<T>& vector, const bool printContent=true) {
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
	ofs << val << std::endl;
}
