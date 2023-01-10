#include "../common/map_common.cpp"

std::string testName("max_size");

template <class T, class U>
void test_for_type();

int main(void)
{
    INIT_SIGNAL();
	test_for_type<char, char>();
	test_for_type<unsigned char, unsigned char>();
	test_for_type<int, int>();
	test_for_type<long, long>();
	test_for_type<float, float>();
	test_for_type<std::string, std::string>();
	test_for_type<TestStruct, TestStruct>();

	test_for_type<char, int>();
	test_for_type<unsigned char, char>();
	test_for_type<int, long>();
	test_for_type<long, TestStruct>();
	test_for_type<float, int>();
	test_for_type<std::string, long>();
	test_for_type<TestStruct, unsigned char>();

	ofs.close();
}

template <class T, class U>
void test_for_type()
{// Test maxsize with different type
	TEST_INIT();
	CURRENT_NAMESPACE::map<T, U> m;
	write_result(ofs, m.max_size());
}
