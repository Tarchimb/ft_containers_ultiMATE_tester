#include "../common/stack_common.cpp"

std::string testName("pop");

template <typename T>
void test_for_type(const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(1);
	test_for_type<TestStruct>(TestStruct(1, 1, "1"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Pop back with filled vector
		TEST_INIT();

		CURRENT_NAMESPACE::stack<T> stack;

		for (int i = 0; i < 50; i++)
			stack.push(value * i);

		const int SIZE = stack.size();
		write_result(ofs, SIZE);
		for (int i = 0; i < SIZE; i++)
		{
			if (i == SIZE / 2)
				write_result(ofs, stack); // half way check
			stack.pop();
		}
		write_result(ofs, stack);
	}
	{ // Pop back with empty stack
		TEST_INIT();

		CURRENT_NAMESPACE::stack<T> stack;
		const int SIZE = stack.size();
		write_result(ofs, SIZE);
		for (int i = 0; i < SIZE; i++)
		{
			if (i == SIZE / 2)
				write_result(ofs, stack); // half way check
			stack.pop();
		}
		write_result(ofs, stack);
	}
}
