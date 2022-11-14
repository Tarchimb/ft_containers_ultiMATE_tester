#include "../common.cpp"

std::string testName("end");
std::ofstream ofs;

template <typename T>
void test_for_type(std::ofstream& ofs, vector<T>& vector1);

int main(int argc, char** argv)
{
	vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(ofs, v1);

	vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(ofs, v2);

	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(ofs, v3);

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, vector<T>& vector1)
{
	change_ofs_to_next_test(ofs, testName);
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	ofs << "test on line: " << __LINE__ << std::endl;
	typename vector<T>::const_iterator it = vector1.end();
	write_result<T>(ofs, *--it);
	typename vector<T>::iterator it2 = vector1.end();
	write_result<T>(ofs, (*--it2));
	write_result<bool>(ofs, &(*it2) == &(*it));
}
