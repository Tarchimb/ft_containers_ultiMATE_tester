#include "../common.cpp"

int test = 1;
std::string testName("data");

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
	const typename vector<T>::value_type* cval = vector1.data();
	write_result(ofs, *cval);
	typename vector<T>::value_type* val = vector1.data();
	*val = *val * 2;
	write_result(ofs, *val);
	write_result(ofs, *(vector1.data()));
	write_result(ofs, &(*val) == &(*cval));
	write_result(ofs, &(*val) == &(*vector1.begin()));
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<int> v1(10, 0);
	for (int i = 0; i < v1.size(); i++)
		v1[i] = i + 1;
	test_for_type<int>(ofs, v1);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<double> v2(1000, 42.424242f);
	for (int i = 0; i < v2.size(); i++)
		v2[i] = i + 1;
	test_for_type<double>(ofs, v2);

	change_ofs_to_next_test(ofs);
	ofs << "test on line: " << __LINE__ << std::endl;
	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	for (int i = 0; i < v3.size(); i++)
		v3[i] = TestStruct(i + 1, i + 1, std::string(std::to_string(i + 1)));
	test_for_type<TestStruct>(ofs, v3);

	ofs.close();
}
