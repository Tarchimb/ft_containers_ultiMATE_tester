#include "../map_common.cpp"

std::string testName("iterator");

template <typename T, typename U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& map);

template <typename T, typename U>
void test_forward_iterator(CURRENT_NAMESPACE::map<T, U>& map);
template <typename T, typename U>
void test_bidirectional_iterator(CURRENT_NAMESPACE::map<T, U>& map);

int main(int argc, char** argv)
{
	CURRENT_NAMESPACE::map<int, int> map_int;
	for (int i = 0; i < 1500; i++)
		map_int.insert(CURRENT_NAMESPACE::pair<int, int>(i, i));
	test_for_type<int, int>(map_int);

	ofs.close();
}

template <typename T, typename U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& map)
{
	test_forward_iterator(map);
	test_bidirectional_iterator(map);
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
