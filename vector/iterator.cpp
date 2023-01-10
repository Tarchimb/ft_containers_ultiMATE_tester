#include "../common/vector_common.cpp"

std::string testName("iterator");

template <typename T>
void test_for_type(CURRENT_NAMESPACE::vector<T> array);

template <typename T>
void test_input_iterator(CURRENT_NAMESPACE::vector<T> array);
template <typename T>
void test_forward_iterator(CURRENT_NAMESPACE::vector<T> array);
template <typename T>
void test_bidirectional_iterator(CURRENT_NAMESPACE::vector<T> array);
template <typename T>
void test_random_access_iterator(CURRENT_NAMESPACE::vector<T> array);

template <typename T>
void test_iterator_dereferencing_pointer(CURRENT_NAMESPACE::vector<T> array);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::vector<int> array_int;
	for (int i = 0; i < 10; i++)
		array_int.push_back(i);

	test_for_type<int>(array_int);

	CURRENT_NAMESPACE::vector<TestStruct> array_struct;
	for (int i = 0; i < 10; i++)
		array_struct.push_back(TestStruct(i, i, std::to_string(i)));
	test_for_type<TestStruct>(array_struct);

	ofs.close();
}

template <typename T>
void test_for_type(CURRENT_NAMESPACE::vector<T> array)
{
	test_input_iterator(array);
	test_forward_iterator(array);
	test_bidirectional_iterator(array);
	test_random_access_iterator(array);
}

template <typename T>
void test_input_iterator(CURRENT_NAMESPACE::vector<T> array)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::vector<T>::const_iterator const_iterator;

	{ // Copy constructor
		TEST_INIT();
		iterator it1(array.begin() + 4);
		const_iterator it2(it1);
		write_result(ofs, *it1);
		write_result(ofs, *it2);
		write_result(ofs, it2 == it1);
		write_result(ofs, it2 != it1);
	}
	{ // Operator =
		TEST_INIT();
		iterator it1(array.begin() + 4);
		const_iterator it2 = it1;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
		write_result(ofs, it2 == it1);
		write_result(ofs, it2 != it1);
	}
	{ // Post and pre increment
		TEST_INIT();
		iterator it1(array.begin() + 4);
		it1++;
		write_result(ofs, *it1);
		++it1;
		write_result(ofs, *it1);
		++it1++;
		write_result(ofs, *it1);
	}
	{ // Dereferencing increment
		TEST_INIT();
		iterator it1(array.begin() + 4);
		write_result(ofs, *it1++);
	}
}

template <typename T>
void test_forward_iterator(CURRENT_NAMESPACE::vector<T> array)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::vector<T>::const_iterator const_iterator;

	{ // Default constructor and changing value
		TEST_INIT();

		iterator it1;
		const_iterator it2;

		iterator it3(array.begin() + 4);
		T temp = array[4];
		*it3 = T();
		write_result(ofs, *it3);
		write_result(ofs, array[4]);
		array[4] = temp; // Putting back temp to let array unmodified
	}
}

template <typename T>
void test_bidirectional_iterator(CURRENT_NAMESPACE::vector<T> array)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::vector<T>::const_iterator const_iterator;

	{ // Post decrement and pre decrement
		TEST_INIT();

		iterator it(array.begin() + 9);
		write_result(ofs, *it);
		it--;
		write_result(ofs, *it);
		write_result(ofs, *it--);
		iterator it2 = it;
		write_result(ofs, *it2);
		--it2;
		--it2--;
		write_result(ofs, *it2);
	}
	{ // Decrement with dereference
		TEST_INIT();

		const_iterator cit1;
		const_iterator cit2(array.end() - 3);
		write_result(ofs, *cit2--);
		write_result(ofs, *cit2);
		const_iterator cit3 = cit2;
		write_result(ofs, *cit3--);

		const_iterator cit4 = cit3;
		write_result(ofs, *cit4);
		const_iterator cit5(cit3);
		write_result(ofs, *cit5);
	}
}

template <typename T>
void test_random_access_iterator(CURRENT_NAMESPACE::vector<T> array)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::vector<T>::const_iterator const_iterator;

	{ // Operator + and -
		TEST_INIT();
		iterator it(array.begin());
		it = it + 2;
		write_result(ofs, *it);
		it = 3 + it;
		write_result(ofs, *it);
		it = it - 4;
		write_result(ofs, *it);
		iterator it2(it + 2);
		write_result(ofs, it2 - it);
	}
	{ // Operator <, >, <= and >=
		TEST_INIT();
		iterator it(array.begin() + 4);
		iterator it2(array.begin());
		write_result(ofs, it < it2);
		write_result(ofs, it > it2);
		write_result(ofs, it <= it2);
		write_result(ofs, it >= it2);
		it = it2;
		write_result(ofs, it <= it2);
		write_result(ofs, it >= it2);
	}
	{ // Operator += and -=
		iterator it(array.begin());
		TEST_INIT();
		iterator it2(array.begin() + 4);
		it += 6;
		write_result(ofs, *it);
		it += -1;
		write_result(ofs, *it);

		it -= 3;
		write_result(ofs, *it);
		it -= -1;
		write_result(ofs, *it);
	}
	{ // Operator []
		iterator it(array.begin());
		TEST_INIT();
		iterator it2(array.begin() + 4);
		write_result(ofs, it[3]);
		it += 3;
		write_result(ofs, it[3]);

		it -= 1;
		write_result(ofs, it[3]);
		it -= 2;
		write_result(ofs, it[3]);
	}
}

template<typename T>
void test_iterator_dereferencing_pointer(CURRENT_NAMESPACE::vector<T> array)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::vector<T>::const_iterator const_iterator;

	TEST_INIT();
	const_iterator it = array.begin();
	write_result(ofs, *it);
	iterator it2(array.begin() + 4);
	write_result(ofs, *it2);
	write_result(ofs, *it);

}
