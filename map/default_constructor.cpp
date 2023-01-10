#include "../common/map_common.cpp"

std::string testName = "default_constructor";

template <class T, class U, class C = std::less<T> >
void test_for_type();

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int, int>();
	test_for_type<double, char>();
	test_for_type<std::string, int>();
	test_for_type<TestStruct, double>();
	test_for_type<TestStruct, TestStruct>();
    test_for_type<int, int, ft_greater<int> >();
    test_for_type<double, char, ft_greater<double> >();
    test_for_type<std::string, int, ft_greater<std::string> >();
    test_for_type<TestStruct, TestStruct, ft_greater<TestStruct> >();
    test_for_type<TestStruct, double, ft_greater<TestStruct> >();

    ofs.close();
}

template <class T, class U, class C>
void test_for_type()
{
	TEST_INIT();
	CURRENT_NAMESPACE::map<T, U, C> m;
	write_result(ofs, m, false);
}
