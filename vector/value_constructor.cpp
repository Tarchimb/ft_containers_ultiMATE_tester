#include "../common/vector_common.cpp"

std::string testName("value_constructor");

template <typename T>
void test_for_type(std::ofstream& ofs, const int& count, const T value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(ofs, 5, 42);
	test_for_type<TestStruct>(ofs, 5, TestStruct());

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, const int& count, const T value)
{
	{ // classic count and value
		TEST_INIT();
		try {
			CURRENT_NAMESPACE::vector<T> vector(count, value);
			write_result(ofs, vector);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
	{ // count = 0
		TEST_INIT();
		try {
			CURRENT_NAMESPACE::vector<T> vector(0, value);
			write_result(ofs, vector);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
}
