#include "../common/map_common.cpp"

std::string testName("clear");

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& m);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::map<int, int> m = generate_map<int, int>(20);
	test_for_type<int, int>(m);

	CURRENT_NAMESPACE::map<double, TestStruct> m1 = generate_map<double, TestStruct>(50);
	test_for_type<double, TestStruct>(m1);

	CURRENT_NAMESPACE::map<TestStruct, TestStruct> m2 = generate_map<TestStruct, TestStruct>(50);
	test_for_type<TestStruct, TestStruct>(m2);


	ofs.close();
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& m)
{
	{ // clear empty map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map;
		map.clear();
		write_result(ofs, map);
	}
	{ // clear filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map = generate_map<T, U>(10);
		map.clear();
		write_result(ofs, map);
	}
	{
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U, ft_greater<T> > map = generate_map<T, U, ft_greater<T> >(10);
		map.clear();
		write_result(ofs, map);
	}
	{ // clear filled map then re-insert it
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map = generate_map<T, U>(10);
		map.clear();
		map.insert(m.begin(), m.end());
		write_result(ofs, map);
	}
	{ // clear map multiple times
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map = generate_map<T, U>(10);
		map.clear();
		map.clear();
		map.clear();
		write_result(ofs, map);
	}
	{ // checking iterators validity
		TEST_INIT();
		typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
		CURRENT_NAMESPACE::map<T, U> map = generate_map<T, U>(10);
		iterator it1 = map.begin();
		iterator it2 = map.end();
		map.clear();
		write_result(ofs, map);
		write_result(ofs, it1 == map.begin());
		write_result(ofs, it2 == map.end());
	}
}
