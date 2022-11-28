#include "../common.cpp"

std::string testName = "default_constructor.cpp";

template <class T, class U>
void test_for_type();

int main(void)
{
	test_for_type<int, int>();
	test_for_type<double, char>();
	test_for_type<std::string, int>();
	test_for_type<TestStruct, double>();
	test_for_type<TestStruct, TestStruct>();

	ofs.close();
}

template <class T, class U>
void test_for_type()
{
	TEST_INIT();
	CURRENT_NAMESPACE::map<T, U> m;
	write_result(ofs, m, false);
}
