#include "../common/map_common.cpp"
#include <utility>

std::string testName("operator_equal");

template <class T, class U>
void test_for_type(const T &key, const U &value, const T &key1, const U &value1);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int, int>(1, 1, 2, 2);
	test_for_type<char, char>('a', 'b', 'b', 'c');
	test_for_type<TestStruct, int>(TestStruct(1, 1, "a"), 1, TestStruct(2, 2, "b"), 2);
	ofs.close();
}

template <class T, class U>
void test_for_type(const T &key, const U &value, const T &key1, const U &value1)
{
	{ // Replace empty map with filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map;
		CURRENT_NAMESPACE::map<T, U> map1;
		map1 = map;
		write_result<T>(ofs, map1);
	}
	{ // Replace filled map witht another filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map;
		CURRENT_NAMESPACE::map<T, U> map1;
		for (int i = 0; i < 5; i++)
			map.insert(CURRENT_NAMESPACE::make_pair(key, value));
		for (int i = 0; i < 5; i++)
			map1.insert(CURRENT_NAMESPACE::make_pair(key1, value1));
		map = map1;
		write_result<T>(ofs, map);
	}
	{ // Replace filled map witht another filled map (dst being larger than src)
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map;
		CURRENT_NAMESPACE::map<T, U> map1;
		for (int i = 0; i < 5; i++)
			map.insert(CURRENT_NAMESPACE::make_pair(key, value));
		for (int i = 0; i < 10; i++)
			map1.insert(CURRENT_NAMESPACE::make_pair(key1, value1));
		map = map1;
		write_result<T>(ofs, map);
	}
	{ // Replace filled map witht another filled map (dst being smaller than src)
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map;
		CURRENT_NAMESPACE::map<T, U> map1;
		for (int i = 0; i < 5; i++)
			map.insert(CURRENT_NAMESPACE::make_pair(key, value));
		for (int i = 0; i < 2; i++)
			map1.insert(CURRENT_NAMESPACE::make_pair(key1, value1));
		map = map1;
		write_result<T>(ofs, map);
	}
}
