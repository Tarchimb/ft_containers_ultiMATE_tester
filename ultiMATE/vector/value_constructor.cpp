#include "../common.cpp"

int test = 1;
std::string testName("value_constructor");

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

template <typename T>
void test_for_type(std::ofstream& ofs, const int& count, const T value)
{
	try {
		vector<T> vector(count, value);
		write_result(ofs, vector);
	}
	catch (std::exception& e)
	{
		write_result(ofs, e.what());
	}
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<int>(ofs, 5, 42);
	
	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	test_for_type<TestStruct>(ofs, 5, TestStruct());

	ofs.close();
}
