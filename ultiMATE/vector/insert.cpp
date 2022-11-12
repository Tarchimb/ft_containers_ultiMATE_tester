#include "../common.cpp"

int test = 1;
std::string testName("insert");

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

template <typename T>
void test_first_overload(std::ofstream& ofs, const T& value); // const iterator, const T&
template <typename T>
void test_second_overload(std::ofstream& ofs, const T& value); // const iterator, size_type,  const T&
template <typename T>
void test_third_overload(std::ofstream& ofs, vector<T>& v); // const iterator, inputIt, inputIt

int main(int argc, char** argv)
{
	std::ofstream ofs;

	test_first_overload<int>(ofs, 1);
	test_first_overload<double>(ofs, -5);
	test_first_overload<TestStruct>(ofs, TestStruct(42, 10, "test"));


	test_second_overload<int>(ofs, 1);
	test_second_overload<double>(ofs, -5);
	test_second_overload<TestStruct>(ofs, TestStruct(42, 10, "test"));


	vector<int> v1;
	for (int i = 0; i < 20; i++) v1.push_back(i);
	test_third_overload<int>(ofs, v1);

	vector<double>v2;
	for (int i = 0; i < 20; i++) v2.push_back(i);
	test_third_overload<double>(ofs, v2);

	vector<TestStruct> v3;
	for (int i = 0; i < 20; i++) v3.push_back(TestStruct(i, i, std::string(std::to_string(i))));
	test_third_overload<TestStruct>(ofs, v3);

	ofs.close();
}

template <typename T>
void test_first_overload(std::ofstream& ofs, const T& value)
{
	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<T> v1(10, T());
	typename vector<T>::iterator it = v1.begin();
	v1.insert(it, value);
	write_result(ofs, v1);

	typename vector<T>::const_iterator cit = v1.end() - 5;
	v1.insert(cit, value * 2);
	write_result(ofs, v1);

	v1.clear();
	it = v1.begin();
	v1.insert(it, value * 4);
	write_result(ofs, v1);

	it = v1.end();
	v1.insert(it, value * 8);
	write_result(ofs, v1);

	it = v1.begin();
	v1.insert(it, *it);
	write_result(ofs, v1);
}

template <typename T>
void test_second_overload(std::ofstream& ofs, const T& value)
{
	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<T> v1(10, T());
	typename vector<T>::iterator it = v1.begin();
	v1.insert(it, 5, value);
	write_result(ofs, v1);

	typename vector<T>::const_iterator cit = v1.end() - 5;
	v1.insert(cit, 1000, value * 2);
	write_result(ofs, v1);

	v1.clear();
	it = v1.begin();
	v1.insert(it, 10, value * 4);
	write_result(ofs, v1);

	it = v1.end();
	v1.insert(it, 2, value * 8);
	write_result(ofs, v1);

	it = v1.end();
	v1.insert(it, 0, value * 8);
	write_result(ofs, v1);

	it = v1.begin();
	v1.insert(it, 5, *it);
	write_result(ofs, v1);
}

template <typename T>
void test_third_overload(std::ofstream& ofs, vector<T>& v)
{
	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	typename vector<T>::iterator vBegin = v.begin();
	typename vector<T>::iterator vEnd = v.end();

	vector<T> v1(10, T());
	typename vector<T>::iterator it = v1.begin();
	v1.insert(it, vBegin, vEnd);
	write_result(ofs, v1);

	typename vector<T>::const_iterator cit = v1.end() - 5;
	v1.insert(cit, vBegin, vEnd);
	write_result(ofs, v1);

	vBegin += v.size() / 4;
	vEnd -= v.size() / 4;

	v1.clear();
	it = v1.begin() + v1.size() / 2;
	v1.insert(it, vBegin, vEnd);
	write_result(ofs, v1);

	vBegin = v.begin();
	vEnd = v.begin();
	it = v1.begin();
	v1.insert(it, vBegin, vEnd);
	write_result(ofs, v1);

	vBegin = v1.begin();
	vEnd = v1.end();
	it = v1.end();
	v1.insert(it, vBegin, vEnd);
	write_result(ofs, v1);
}
