#include "../common/vector_common.cpp"

std::string testName("range_constructor");

template <typename T>
void test_for_type(const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(42);
	test_for_type<float>(42.4242);
	test_for_type<TestStruct>(TestStruct(10, 5, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Classic range constructor
		TEST_INIT();
		try {
			CURRENT_NAMESPACE::vector<T> vector1(100, value);
			CURRENT_NAMESPACE::vector<T> vector2(vector1.begin(), vector1.end());
			write_result(ofs, vector2);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
	{ // Range constructor with modified iterators
		TEST_INIT();
		try {
			CURRENT_NAMESPACE::vector<T> vector1(100, value);
			CURRENT_NAMESPACE::vector<T> vector2(vector1.begin() + 25, vector1.end() - 25);
			write_result(ofs, vector2);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
	{ // Range constructor with begin = end
		TEST_INIT();
		try {
			CURRENT_NAMESPACE::vector<T> vector1(100, value);
			CURRENT_NAMESPACE::vector<T> vector2(vector1.begin() + 50, vector1.begin() + 50);
			write_result(ofs, vector2);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
}
