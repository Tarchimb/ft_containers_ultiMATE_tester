#include "../common.cpp"

int test = 1;
std::string testName("rbegin");

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
	typename vector<T>::const_reverse_iterator it = vector1.rbegin();
	write_result<T>(ofs, *it);
	typename vector<T>::reverse_iterator it2 = vector1.rbegin();
	write_result<T>(ofs, (*it2));
	write_result<bool>(ofs, &(*it2) == &(*it));
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(ofs, v1);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(ofs, v2);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[500] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(ofs, v3);


	ofs.close();
}
