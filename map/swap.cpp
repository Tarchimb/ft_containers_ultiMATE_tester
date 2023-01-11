#include "../common/map_common.cpp"

std::string testName("swap");

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> m);

int main(void)
{
    INIT_SIGNAL();

	CURRENT_NAMESPACE::map<int, int> m = generate_map<int, int>(20);
	test_for_type<int, int>(m);

	CURRENT_NAMESPACE::map<double, TestStruct> m1 = generate_map<double, TestStruct>(20);
	test_for_type<double, TestStruct>(m1);

	CURRENT_NAMESPACE::map<TestStruct, TestStruct> m2 = generate_map<TestStruct, TestStruct>(20);
	test_for_type<TestStruct, TestStruct>(m2);
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> map1)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	{ // Test for 2 emtpy map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map2;
		CURRENT_NAMESPACE::map<T, U> map3;
		iterator it1 = map2.begin();
		iterator it2 = map3.begin();

		map3.swap(map2);

		write_result(ofs, map3);
		write_result(ofs, map2);
		ofs << std::boolalpha << (it1 == map2.begin()) << std::endl;
		ofs << std::boolalpha << (it1 == map3.begin()) << std::endl;
	}
	{ // Test for two filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map2 = generate_map<T, U>(10);
		iterator it1 = map1.begin();
		iterator it2 = map2.begin();

		map1.swap(map2);

		write_result(ofs, map1);
		write_result(ofs, *it1);
		write_result(ofs, map2);
		write_result(ofs, *it2);
		ofs << std::boolalpha << (it1 == map1.begin()) << std::endl;
		ofs << std::boolalpha << (it1 == map2.begin()) << std::endl;
	}
	{ // Test for two filled map with custom comparator
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U, ft_greater<T> > map2 = generate_map<T, U, ft_greater<T> >(10);
		CURRENT_NAMESPACE::map<T, U, ft_greater<T> > map3 = generate_map<T, U, ft_greater<T> >(10);
		iterator it1 = map3.begin();
		iterator it2 = map2.begin();

		map3.swap(map2);

		write_result(ofs, map3);
		write_result(ofs, *it1);
		write_result(ofs, map2);
		write_result(ofs, *it2);
		write_result(ofs, it1 == map3.begin());
		write_result(ofs, it1 == map2.begin());
	}
	{ // Test for one emtpy map and one filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U> map2;
		iterator it1 = map1.begin();
		iterator it2 = map2.begin();

		map1.swap(map2);

		write_result(ofs, map1);
		write_result(ofs, map2);
		write_result(ofs, it1 == map1.begin());
		write_result(ofs, it1 == map2.begin());
	}
}
