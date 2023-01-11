#include "../common/stack_common.cpp"

std::string testName("relational_operators");

template <typename T>
void test_for_type(const T& value);

template <typename T>
void test_equal(const T& value);

template <typename T>
void test_less(const T& value);

template <typename T>
void test_greater(const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(10);
	test_for_type<TestStruct>(TestStruct(1, 1, "1"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	test_equal(value);
	test_less(value);
	test_greater(value);
}

template <typename T>
void test_equal(const T& value)
{
	CURRENT_NAMESPACE::stack<T> low, high;
	{
		for (int i = 0; i < 5; i++)
		{
			low.push(value * i);
			high.push(value * i * 2);
		}

		{ // Equal with same size
			TEST_INIT();
			write_result(ofs, low == high);
			write_result(ofs, low == low);
			write_result(ofs, high == high);
		}
		{ // Not equal with same size
			TEST_INIT();
			write_result(ofs, low != high);
			write_result(ofs, low != low);
			write_result(ofs, high != high);
		}
	}

	{
		for (int i = 0; i < 5; i++)
			low.push(value * i);
		for (int i = 0; i < 3; i++)
			high.push(value * i * 2);

		{ // Equal with different size
			TEST_INIT();
			write_result(ofs, low == high);
			write_result(ofs, low == low);
			write_result(ofs, high == high);
		}
		{ // Not equal with different size
			TEST_INIT();
			write_result(ofs, low != high);
			write_result(ofs, low != low);
			write_result(ofs, high != high);
		}
	}
}

template <typename T>
void test_less(const T& value)
{
	CURRENT_NAMESPACE::stack<T> low, high;
	{
		for (int i = 0; i < 5; i++)
		{
			low.push(value * i);
			high.push(value * i * 2);
		}

		{ // Less than with same size
			TEST_INIT();
			write_result(ofs, low < high);
			write_result(ofs, low < low);
			write_result(ofs, high < high);
		}
		{ // Less or equal with same size
			TEST_INIT();
			write_result(ofs, low <= high);
			write_result(ofs, low <= low);
			write_result(ofs, high <= high);
		}
	}

	{
		for (int i = 0; i < 5; i++)
			low.push(value * i);
		for (int i = 0; i < 3; i++)
			high.push(value * i * 2);

		{ // Less than with different size
			TEST_INIT();
			write_result(ofs, low < high);
			write_result(ofs, low < low);
			write_result(ofs, high < high);
		}
		{ // Less or equal with different size
			TEST_INIT();
			write_result(ofs, low <= high);
			write_result(ofs, low <= low);
			write_result(ofs, high <= high);
		}
	}
}

template <typename T>
void test_greater(const T& value)
{
	CURRENT_NAMESPACE::stack<T> low, high;
	{
		for (int i = 0; i < 5; i++)
		{
			low.push(value * i);
			high.push(value * i * 2);
		}

		{ // Greater than with same size
			TEST_INIT();
			write_result(ofs, low > high);
			write_result(ofs, low > low);
			write_result(ofs, high > high);
		}
		{ // Greater or equal with same size
			TEST_INIT();
			write_result(ofs, low >= high);
			write_result(ofs, low >= low);
			write_result(ofs, high >= high);
		}
	}
	
	{
		for (int i = 0; i < 5; i++)
			low.push(value * i);
		for (int i = 0; i < 3; i++)
			high.push(value * i * 2);

		{ // Greater than with different size
			TEST_INIT();
			write_result(ofs, low > high);
			write_result(ofs, low > low);
			write_result(ofs, high > high);
		}
		{ // Greater or equal with different size
			TEST_INIT();
			write_result(ofs, low >= high);
			write_result(ofs, low >= low);
			write_result(ofs, high >= high);
		}
	}
}
