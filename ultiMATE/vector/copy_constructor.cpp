#include "../common.cpp"
#include <fstream>

std::string testName("copy_constructor");
std::ofstream ofs;

template <typename T>
void test_for_type(const vector<T>& vector1);

int main(int argc, char** argv)
{
	vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(v1);

	vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(v2);

	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(v3);

	ofs.close();
}

template <typename T>
void test_for_type(const vector<T>& vector1)
{
	change_ofs_to_next_test(ofs, testName);
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	ofs << "test on line: " << __LINE__ << std::endl;

	vector<T> vector2(vector1);
	write_result<T>(ofs, vector2);
}

