#include "../common/vector_common.cpp"

std::string testName = "default_constructor";

template <typename T>
void test_for_type();

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>();
	test_for_type<double>();
	test_for_type<TestStruct>();
	test_for_type< CURRENT_NAMESPACE::vector<int> >();
	test_for_type<std::string>();

	ofs.close();
}

template <typename T>
void test_for_type()
{
	TEST_INIT();
	CURRENT_NAMESPACE::vector<T> vector;
	write_result<T>(ofs, vector, false);
}
