#include "../common/map_common.cpp"

std::string testName("reverse_iterator");

template <typename T, typename U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& map);

template <typename T, typename U>
void test_forward_iterator(CURRENT_NAMESPACE::map<T, U>& map);
template <typename T, typename U>
void test_bidirectional_iterator(CURRENT_NAMESPACE::map<T, U>& map);
template <typename T, typename U>
void test_iteration_iterator(CURRENT_NAMESPACE::map<T, U>& map);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::map<int, int> map_int = generate_map<int, int>(50);
	CURRENT_NAMESPACE::map<int, TestStruct> map_int_struct = generate_map<int, TestStruct>(50);
	CURRENT_NAMESPACE::map<double, int> map_double_int = generate_map<double, int>(50);
	CURRENT_NAMESPACE::map<float, float> map_float = generate_map<float, float>(50);
    CURRENT_NAMESPACE::map<TestStruct, TestStruct> map_struct = generate_map<TestStruct, TestStruct>(50);

    test_for_type<int, int>(map_int);
    test_for_type<int, TestStruct>(map_int_struct);
    test_for_type<double, int>(map_double_int);
    test_for_type<float, float>(map_float);
    test_for_type<TestStruct, TestStruct>(map_struct);

	ofs.close();
}

template <typename T, typename U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& map)
{
	test_forward_iterator(map);
	test_bidirectional_iterator(map);
    test_iteration_iterator(map);
}


template <typename T, typename U>
void test_forward_iterator(CURRENT_NAMESPACE::map<T, U>& map)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::reverse_iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_reverse_iterator const_iterator;

	{ // Copy constructor
		TEST_INIT();
		iterator it1(map.rbegin());
		const_iterator it2(it1);

		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Operator =
		TEST_INIT();
		iterator it1(map.rbegin());
		const_iterator it2 = it1;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
		write_result(ofs, it2 == it1);
		write_result(ofs, it2 != it1);
	}
	{ // Post and pre increment
		TEST_INIT();
		iterator it1(map.rbegin());
		it1++;
		write_result(ofs, *it1);
		++it1;
		write_result(ofs, *it1);
		++it1++;
		write_result(ofs, *it1);
		it1++;
		write_result(ofs, *it1);
	}
	{ // Dereferencing increment
		TEST_INIT();
		iterator it1(map.rbegin());
		write_result(ofs, *it1++);
	}
	{ // Accessing first and second
		TEST_INIT();
		iterator it1(map.rbegin());
		write_result(ofs, it1->first);
		write_result(ofs, it1->second);
		it1++;
		it1++;
		it1++;
		write_result(ofs, it1->first);
		write_result(ofs, it1->second);
	}
	{ // Equality operators
		TEST_INIT();
		iterator it1(map.rbegin());
		const_iterator it2(it1);

		write_result(ofs, it1 == it2);
		write_result(ofs, it1 != it2);
		++it1;
		write_result(ofs, it1 == it2);
		write_result(ofs, it1 != it2);
		++it2;
		write_result(ofs, it1 == it2);
		write_result(ofs, it1 != it2);
	}
	{ // Navigate through whole tree
		TEST_INIT();
		iterator it1(map.rbegin());
		while (it1 != map.rend())
			write_result(ofs, *it1++);
	}
    { //Test adress at init
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U> empty_map;
        iterator it = empty_map.rbegin();
        const_iterator cit = empty_map.rbegin();
        iterator rend = empty_map.rend();
        const_iterator cend = empty_map.rend();

        write_result(ofs, it == rend);
        write_result(ofs, cit == cend);
        write_result(ofs, it == cend);
        write_result(ofs, cit == rend);
    }
}

template <typename T, typename U>
void test_bidirectional_iterator(CURRENT_NAMESPACE::map<T, U>& map)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::reverse_iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_reverse_iterator const_iterator;

	{ // Pre decrement
		TEST_INIT();
		iterator it1(map.rend());
		const_iterator it2(it1);

		--it1;
		--it2;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Post decrement
		TEST_INIT();
		iterator it1(map.rend());
		const_iterator it2(it1);

		it1--;
		it2--;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Pre and post increment
		TEST_INIT();
		iterator it1(map.rend());
		const_iterator it2(it1);

		--it1--;
		--it2--;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Navigate through the whole tree 
		TEST_INIT();
		iterator it1(map.rend());
		--it1;
		while (it1 != map.rbegin())
			write_result(ofs, *it1--);
	}

}
template <typename T, typename U>
void test_iteration_iterator(CURRENT_NAMESPACE::map<T, U>& map) {
	typedef typename CURRENT_NAMESPACE::map<T, U>::reverse_iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_reverse_iterator const_iterator;

	{ //Iterate forward from rbegin
	    TEST_INIT();
	    for (iterator it = map.rbegin(); it != map.rend(); it++)
	    {
	        write_result(ofs, *it);
	    }
	}
	{ //Iterate backward from rend
	    TEST_INIT();
	    for (iterator it = map.rend(); it != map.rend(); it--)
	    {
	        write_result(ofs, *it);
	    }
	}
}
