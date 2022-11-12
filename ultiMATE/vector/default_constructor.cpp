#include "../common.cpp"

int test = 1;
std::string testName("default_constructor");

template <typename T>
void test_for_type(std::ofstream& ofs)
{
	vector<T> vector;
		write_result<T>(ofs, vector, false);
}

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<int>(ofs);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<TestStruct>(ofs);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<double>(ofs);

	//test< vector<int> >(ofs);

	ofs.close();
}
