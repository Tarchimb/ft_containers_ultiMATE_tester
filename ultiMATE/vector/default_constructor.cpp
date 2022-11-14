#include "../common.cpp"

std::string testName = "default_constructor";
std::ofstream ofs;

template <typename T>
void test_for_type();

int main(int argc, char** argv)
{
	test_for_type<int>();
	test_for_type<double>();
	test_for_type<TestStruct>();
	test_for_type< vector<int> >();
	test_for_type<std::string>();

	ofs.close();
}

template <typename T>
void test_for_type()
{
	change_ofs_to_next_test(ofs, testName);
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	ofs << "test on line: " << __LINE__ << std::endl;

	vector<T> vector;
	write_result<T>(ofs, vector, false);
}
