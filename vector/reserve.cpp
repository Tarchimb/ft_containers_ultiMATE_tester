#include "../common.cpp"

int test = 1;
std::string testName("reserve");

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

template <typename T>
void test_for_type(std::ofstream& ofs, vector<T>& vector1)
{
	write_result<typename vector<T>::difference_type>(ofs, vector1.capacity());
}

template <typename T>
void test_for_type(std::ofstream& ofs)
{
	vector<T> v; test_for_type<T>(ofs, v);
	v.reserve(5); test_for_type<T>(ofs, v);
	write_result(ofs, v);
	v.reserve(2); test_for_type<T>(ofs, v);
	write_result(ofs, v);
	try { v.reserve(-2); test_for_type<T>(ofs, v); }
	catch (std::exception& e) { write_result(ofs, "throw on invalid reserve"); }
	v.reserve(0); test_for_type<T>(ofs, v);
	write_result(ofs, v);
	v.reserve(100); test_for_type<T>(ofs, v);
	write_result(ofs, v);
	v.reserve(100); test_for_type<T>(ofs, v);
	write_result(ofs, v);
	v.reserve(20000); test_for_type<T>(ofs, v);
	write_result(ofs, v);
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<int>(ofs);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<double>(ofs);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<TestStruct>(ofs);

	ofs.close();
}
