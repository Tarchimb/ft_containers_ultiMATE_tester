#include "../common/stack_common.cpp"

std::string testName("operator_equal");

template <typename T>
void test_for_type(const CURRENT_NAMESPACE::stack<T>& stack, const T& value);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::stack<int> stack;
	for (int i = 0; i < 50; i++)
		stack.push(5 * i);
	test_for_type<int>(stack, 42);

	CURRENT_NAMESPACE::stack<double> stack2; 
	for (int i = 0; i < 50; i++)
		stack2.push(3.2f * i);
	test_for_type<double>(stack2, 42.0f);

	CURRENT_NAMESPACE::stack<TestStruct> stack3;
	for (int i = 0; i < 50; i++)
		stack3.push(TestStruct(10, 42, "test"));
	test_for_type<TestStruct>(stack3, TestStruct(1, 2, "3"));


	ofs.close();
}

template <typename T>
void test_for_type(const CURRENT_NAMESPACE::stack<T>& stack, const T& value)
{
	{ // Replace empty stack with another empty stack
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> stack;
		CURRENT_NAMESPACE::stack<T> stack2;
		stack = stack2;
		write_result<T>(ofs, stack);
	}
	{ // Replace empty stack with filled stack
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> stack2;
		stack2 = stack;
		write_result<T>(ofs, stack2);
	}
	{ // Replace filled stack witht another filled stack
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> stack2;
		for (int i = 0; i < 5; i++)
			stack2.push(value);
		stack2 = stack;
		write_result<T>(ofs, stack2);
	}
	{ // Replace filled stack witht another filled stack (dst being larger than src)
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> stack2;
		for (int i = 0; i < 5; i++)
			stack2.push(value);
		stack2 = stack;
		write_result<T>(ofs, stack);
	}
	{ // Replace filled stack witht another filled stack (dst being smaller than src)
		TEST_INIT();
		CURRENT_NAMESPACE::stack<T> stack2;
		for (int i = 0; i < 5; i++)
			stack2.push(value);
		stack2 = stack;
		write_result<T>(ofs, stack);
	}
}
