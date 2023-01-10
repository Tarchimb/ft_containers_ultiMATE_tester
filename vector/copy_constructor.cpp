#include "../common/vector_common.cpp"

std::string testName("copy_constructor");

template <typename T>
void test_for_type(const CURRENT_NAMESPACE::vector<T>& vector1);

template <typename T>
void test_for_capacity(const CURRENT_NAMESPACE::vector<T> vector1);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(v1);

	CURRENT_NAMESPACE::vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(v2);

	CURRENT_NAMESPACE::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(v3);

	CURRENT_NAMESPACE::vector<int> v11(10, 42);
	v11.reserve(20);
	test_for_capacity<int>(v11);

	CURRENT_NAMESPACE::vector<double> v22(100, 42.424242f);
	v11.reserve(130);
	test_for_capacity<double>(v22);

	CURRENT_NAMESPACE::vector<TestStruct> v33(100, TestStruct(10, 42, "test"));
	v33.reserve(110);
	test_for_capacity<TestStruct>(v33);

	ofs.close();
}

template <typename T>
void test_for_type(const CURRENT_NAMESPACE::vector<T>& vector1)
{
	TEST_INIT();
	CURRENT_NAMESPACE::vector<T> vector2(vector1);
	write_result<T>(ofs, vector2);
}

template <typename T>
void test_for_capacity(const CURRENT_NAMESPACE::vector<T> vector1)
{
	TEST_INIT();
	write_result<T>(ofs, vector1);
}
