#include "../common/map_common.cpp"

std::string testName = "count";

template <class T, class U>
void test_for_type();

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int, int>();
	test_for_type<TestStruct, int>();
	test_for_type<TestStruct, TestStruct>();

	ofs.close();
}

template <class T, class U>
void test_for_type()
{
	{ // Count with unitialized map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m;
		write_result(ofs, m.count(T()));
	}
	{ // Count with filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m;
		T key = T();
		U value = U();
		for (int i = 0; i < 15; i++)
		{
			m.insert(CURRENT_NAMESPACE::pair<T, U>(key, value));
			write_result(ofs, m.count(key)); // Search inserted key
			++key;
			++value;
			write_result(ofs, m.count(key)); // Search key not yet inserted
		}
	}
}
