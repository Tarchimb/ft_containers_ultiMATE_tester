#include "../common.cpp"

int test = 1;
std::string testName("range_constructor");
void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

template <typename T>
void test_for_type(std::ofstream& ofs, vector<T>& v)
{
	try {
		write_result(ofs, v);
	}
	catch (std::exception& e)
	{
		write_result(ofs, e.what());
	}
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	vector<int> v_int(5, 42);
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<int> v1(v_int.begin(), v_int.end());
		test_for_type<int>(ofs, v1);
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<int> v1(v_int.begin() + 1, v_int.end() - 2);
		test_for_type<int>(ofs, v1);
	}

	vector<float> v_float(1000, 0.0f);
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<float> v1(v_float.begin(), v_float.end());
		test_for_type<float>(ofs, v1);
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<float> v1(v_float.begin() + 100, v_float.end() - 200);
		test_for_type<float>(ofs, v1);
	}

	TestStruct structTest(10, 50, "test_for_type");
	vector<TestStruct> v_struct(1000, structTest);
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<TestStruct> v1(v_struct.begin(), v_struct.end());
		test_for_type<TestStruct>(ofs, v1);
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<TestStruct> v1(v_struct.begin() + 100, v_struct.end() - 200);
		test_for_type<TestStruct>(ofs, v1);
	}

	ofs.close();
}
