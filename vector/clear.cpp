#include "../common.cpp"
#include <exception>

int test = 1;
std::string testName("clear");

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

template <typename T>
void test_for_type(std::ofstream& ofs, vector<T>& vector1, const T& value)
{
	vector1.clear();
	write_result(ofs, vector1);
	for (int i = 0; i < 10; i++)
		vector1.push_back(value * i);
	write_result(ofs, vector1);
	vector1.clear();
	write_result(ofs, vector1);
	for (int i = 0; i < 10; i++)
		vector1.push_back(value * i);
	for (int i = 0; i < 5; i++)
		vector1.pop_back();
	write_result(ofs, vector1);
	vector1.clear();
	write_result(ofs, vector1);
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<int> v1(10, 0);
	test_for_type<int>(ofs, v1, 1);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<double> v2(1000, 42.424242f);
	test_for_type<double>(ofs, v2, 1);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	test_for_type<TestStruct>(ofs, v3, TestStruct(1, 1, "1"));


	ofs.close();
}
