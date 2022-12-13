#include "../map_common.cpp"

std::string testName("iterator");

template <typename T, typename U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& map);

template <typename T, typename U>
void test_forward_iterator(CURRENT_NAMESPACE::map<T, U>& map);
template <typename T, typename U>
void test_bidirectional_iterator(CURRENT_NAMESPACE::map<T, U>& map);
template <typename T, typename U>
void test_iteration_iterator(CURRENT_NAMESPACE::map<T, U>& map);

int main(int argc, char** argv)
{
	CURRENT_NAMESPACE::map<int, int> map_int;
    CURRENT_NAMESPACE::map<std::string, std::string> map_string;
    CURRENT_NAMESPACE::map<TestStruct, TestStruct> map_struct;

    for (int i = 0; i < 1500; i++)
    {
        map_int.insert(CURRENT_NAMESPACE::pair<int, int>(i, i));
        map_string.insert(CURRENT_NAMESPACE::pair<std::string, std::string>(std::to_string(i), std::to_string(i)));
        map_struct.insert(CURRENT_NAMESPACE::pair<TestStruct, TestStruct>(TestStruct(i, i, std::to_string(i)), TestStruct(i, i, std::to_string(i))));
    }
    test_for_type<int, int>(map_int);
    test_for_type<std::string, std::string>(map_string);
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
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;

	{ // Copy constructor
		TEST_INIT();
		iterator it1(map.begin());
		const_iterator it2(it1);

		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Operator =
		TEST_INIT();
		iterator it1(map.begin());
		const_iterator it2 = it1;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
		write_result(ofs, it2 == it1);
		write_result(ofs, it2 != it1);
	}
	{ // Post and pre increment
		TEST_INIT();
		iterator it1(map.begin());
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
		iterator it1(map.begin());
		write_result(ofs, *it1++);
	}
	{ // Accessing first and second
		TEST_INIT();
		iterator it1(map.begin());
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
		iterator it1(map.begin());
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
		iterator it1(map.begin());
		while (it1 != map.end())
			write_result(ofs, *it1++);
	}
    { //Test adress at init
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U> empty_map;
        iterator it = empty_map.begin();
        const_iterator cit = empty_map.begin();
        iterator end = empty_map.end();
        const_iterator cend = empty_map.end();

        write_result(ofs, it == end);
        write_result(ofs, cit == cend);
        write_result(ofs, it == cend);
        write_result(ofs, cit == end);
    }
}

template <typename T, typename U>
void test_bidirectional_iterator(CURRENT_NAMESPACE::map<T, U>& map)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;

	{ // Pre decrement
		TEST_INIT();
		iterator it1(map.end());
		const_iterator it2(it1);

		--it1;
		--it2;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Post decrement
		TEST_INIT();
		iterator it1(map.end());
		const_iterator it2(it1);

		it1--;
		it2--;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Pre and post increment
		TEST_INIT();
		iterator it1(map.end());
		const_iterator it2(it1);

		--it1--;
		--it2--;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
	}
	{ // Dereference + decrement
		TEST_INIT();
		iterator it1(map.end());
		const_iterator it2(it1);

		*it1--;
		*it2--;
		write_result(ofs, *it1--);
		write_result(ofs, *it2--);
	}
	{ // Navigate through the whole tree 
		TEST_INIT();
		iterator it1(map.end());
		--it1;
		while (it1 != map.begin())
			write_result(ofs, *it1--);
	}

}
    template <typename T, typename U>
    void test_iteration_iterator(CURRENT_NAMESPACE::map<T, U>& map) {
        typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
        typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;

        { //Iterate forward from begin
            TEST_INIT();
            for (iterator it = map.begin(); it != map.end(); it++)
            {
                write_result(ofs, *it);
            }
        }
        { //Iterate backward from end
            TEST_INIT();
            for (iterator it = map.end(); it != map.end(); it--)
            {
                write_result(ofs, *it);
            }
        }
    }
