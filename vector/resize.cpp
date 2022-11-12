#include "../common.cpp"

int test = 1;
std::string testName("resize");

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value);

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	test++;
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	test_for_type<int>(ofs, 10);
	test_for_type<float>(ofs, 10.5f);
	test_for_type<TestStruct>(ofs, TestStruct(5, -42, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value)
{
	{
		change_ofs_to_next_test(ofs);
		vector<T> v;
		v.resize(5, value);
		write_result(ofs, v);
	}

	{
		change_ofs_to_next_test(ofs);
		vector<T> v(50);
		v.resize(5, value);
		write_result(ofs, v);
	}

	{
		change_ofs_to_next_test(ofs);
		vector<T> v(30, value);
		v.resize(5, value);
		write_result(ofs, v);
	}

	{
		change_ofs_to_next_test(ofs);
		vector<T> v(5, value);
		v.resize(0, value);
		write_result(ofs, v);
	}

	{
		change_ofs_to_next_test(ofs);
		vector<T> v(5, value);
		v.resize(5, value);
		v.resize(5, T());
		v.resize(9, value);
		v.resize(9, T());
		v.resize(2, value);
		v.resize(2, T());
		write_result(ofs, v);
	}

	{
		change_ofs_to_next_test(ofs);
		vector<T> v(5, value);
		v.resize(40000, value);
		write_result(ofs, v);
	}
}

