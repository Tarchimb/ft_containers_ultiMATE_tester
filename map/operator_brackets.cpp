#include "../common/map_common.cpp"

std::string testName("operator_brackets");

template<typename T>
void test_for_type(const T& val1, const T& val2);

int main(void)
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
	{// Check if it return the right values
		TEST_INIT();

		CURRENT_NAMESPACE::map<int, T> map;

		map.insert(CURRENT_NAMESPACE::make_pair(1, val1));
		map.insert(CURRENT_NAMESPACE::make_pair(2, val2));

		ofs << std::boolalpha << (map[1] == val1) << std::endl;
		ofs << std::boolalpha << (map[2] == val2) << std::endl;
	}

	{// Check if it return the right values
		TEST_INIT();

		CURRENT_NAMESPACE::map<int, T> map;

		map.insert(CURRENT_NAMESPACE::make_pair(1, val1));
		map.insert(CURRENT_NAMESPACE::make_pair(2, val2));

		map[2] = map[1];

		ofs << std::boolalpha << (map[1] == map[2]) << std::endl;
	}
}
