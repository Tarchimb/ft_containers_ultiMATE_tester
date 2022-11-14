#include "../common.cpp"

std::string testName = "default_constructor";

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
	TEST_INIT();
	vector<T> vector;
	write_result<T>(ofs, vector, false);
}
