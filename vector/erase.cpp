#include "../common.cpp"

int test = 1;
std::string testName("erase");

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value);

// CHANGE FIRST OVERLOAD WITH OVERLOAD NAME (MORE EXPLICIT NAMES)
// RELY ON MORE DEFINE (REMOVE HARD CODED VALUES IN MAIN)
// ADD VECTOR T TYPEDEF IN COMMON
// TIMER ?

template <typename T>
void test_first_overload(std::ofstream& ofs, const T& value);
template <typename T>
void test_second_overload(std::ofstream& ofs, const T& value);

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

	test_for_type<int>(ofs, 10);
	test_for_type<float>(ofs, 10.5f);
	test_for_type<TestStruct>(ofs, TestStruct(5, -42, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value)
{
	test_first_overload<T>(ofs, value);
	test_second_overload<T>(ofs, value);
}

template <typename T>
void test_first_overload(std::ofstream& ofs, const T& value)
{
	typedef typename vector<T>::iterator iterator;

	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.begin());
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.begin() + 2);
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(1, value);
		iterator it = v.erase(v.begin());
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.end() - 1);
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.end()));
	}
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(1);
		iterator it = v.erase(v.begin());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
}

template <typename T>
void test_second_overload(std::ofstream& ofs, const T& value)
{
	typedef typename vector<T>::iterator iterator;
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.begin(), v.end());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	typedef typename vector<T>::iterator iterator;
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.begin() + 1, v.end() - 1);
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	typedef typename vector<T>::iterator iterator;
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.begin() + 1, v.begin() + v.size());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	typedef typename vector<T>::iterator iterator;
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.end() - 3, v.end());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	typedef typename vector<T>::iterator iterator;
	{
		change_ofs_to_next_test(ofs);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(5, value);
		iterator it = v.erase(v.begin(), v.begin());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
}





