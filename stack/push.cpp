#include "../common/stack_common.cpp"

std::string testName("push");

template <typename T>
void test_for_type(const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(42);
	test_for_type<TestStruct>(TestStruct(1, 1, "1"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Multiple push back
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> v;
		for (int i = 0; i < 50; i++)
			v.push(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with a lot of values
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> v;
		for (int i = 0; i < 10000; i++)
			v.push(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with a lot of values and specific container
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T, CURRENT_NAMESPACE::vector<T> > v;
		for (int i = 0; i < 10000; i++)
			v.push(value * i);
		write_result(ofs, v);
	}
}
