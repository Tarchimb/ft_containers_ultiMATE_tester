#include "../common/map_common.cpp"

std::string testName("value_comp");

template<typename T>
void test_for_type(const T& val1, const T& val2);

int main()
{
    INIT_SIGNAL();
	    // Test the function with various data types
    test_for_type<int>(1, 2);
    test_for_type<int>(2, 1);

    test_for_type<char>('a', 'b');
    test_for_type<char>('b', 'a');

    test_for_type<std::string>("a", "b");
    test_for_type<std::string>("b", "a");

    test_for_type<TestStruct>(TestStruct(15, 8, "a"), TestStruct(8, 15, "c"));
    test_for_type<TestStruct>(TestStruct(8, 15, "c"), TestStruct(15, 8, "a"));
}


template<typename T>
void test_for_type(const T& val1, const T& val2)
{
	{// Compare values of type T
		TEST_INIT();
		typedef typename CURRENT_NAMESPACE::map<int, T>::iterator iterator;
		CURRENT_NAMESPACE::map<int, T> map;

		map.insert(CURRENT_NAMESPACE::make_pair(1, val1));
		map.insert(CURRENT_NAMESPACE::make_pair(2, val2));
		iterator it = map.begin();
		iterator it2 = it;
		it2++;
		ofs << std::boolalpha << map.value_comp()(*it, *it2) << std::endl;
	}
}
