#include "../common/vector_common.cpp"

std::string testName("push_back");

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
		CURRENT_NAMESPACE::vector<T> v;
		for (int i = 0; i < 50; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with existing values in vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(20, value);
		for (int i = 0; i < 30; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with a lot of values
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with a lot of values and existing values in vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10000, value);
		for (int i = 0; i < 10000; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with pre-reserved space
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		v.reserve(100);
		for (int i = 0; i < 30; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with pre-reserved space but not enough
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		v.reserve(10);
		for (int i = 0; i < 30; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}

}
