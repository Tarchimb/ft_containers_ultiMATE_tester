#include "../common.cpp"

std::string testName("iterator");
std::ofstream ofs;

template <typename T>
void test_for_type(T* array);

template <typename T>
void test_input_iterator(T* array);
template <typename T>
void test_forward_iterator(T* array);
template <typename T>
void test_bidirectional_iterator(T* array);
template <typename T>
void test_random_access_iterator(T* array);

int main(int argc, char** argv)
{
	int array_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
	test_for_type<int>(array_int);

	TestStruct array_struct[10];
	for (int i = 0; i < 10; i++)
		array_struct[i] = TestStruct(i, i, std::to_string(i));
	test_for_type<TestStruct>(array_struct);

	ofs.close();
}

template <typename T>
void test_for_type(T* array)
{
	test_input_iterator(array);
	test_forward_iterator(array);
	test_bidirectional_iterator(array);
	test_random_access_iterator(array);
}

template <typename T>
void test_input_iterator(T* array)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	{ // Dereferencing pointer
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		const_iterator it = array; // Be careful, this type is "const iterator" and not "const_iterator"
		write_result(ofs, *it);
		iterator it2(array + 4);
		write_result(ofs, *it2);
		write_result(ofs, *it);
	}
	{ // Copy constructor
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it1(array + 4);
		const_iterator it2(it1);
		write_result(ofs, *it1);
		write_result(ofs, *it2);
		write_result(ofs, it2 == it1);
		write_result(ofs, it2 != it1);
	}
	{ // Operator =
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it1(array + 4);
		const_iterator it2 = it1;
		write_result(ofs, *it1);
		write_result(ofs, *it2);
		write_result(ofs, it2 == it1);
		write_result(ofs, it2 != it1);
	}
	{ // Post and pre increment
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it1(array + 4);
		it1++;
		write_result(ofs, *it1);
		++it1;
		write_result(ofs, *it1);
		++it1++;
		write_result(ofs, *it1);
	}
	{ // Dereferencing increment
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it1(array + 4);
		write_result(ofs, *it1++);
	}
}

template <typename T>
void test_forward_iterator(T* array)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	{ // Default constructor and changing value
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;

		iterator it1;
		const_iterator it2;

		iterator it3(array + 4);
		T temp = array[4];
		*it3 = T();
		write_result(ofs, *it3);
		write_result(ofs, array[4]);
		array[4] = temp; // Putting back temp to let array unmodified
	}
}

template <typename T>
void test_bidirectional_iterator(T* array)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	{ // Post decrement and pre decrement
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;

		iterator it(array + 9);
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
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;

		const_iterator cit1;
		const_iterator cit2(array + 3);
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
void test_random_access_iterator(T* array)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	{ // Operator + and -
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it(array);
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
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it(array + 4);
		iterator it2(array);
		write_result(ofs, it < it2);
		write_result(ofs, it > it2);
		write_result(ofs, it <= it2);
		write_result(ofs, it >= it2);
		it = it2;
		write_result(ofs, it <= it2);
		write_result(ofs, it >= it2);
	}
	{ // Operator += and -=
		iterator it(array);
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it2(array + 4);
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
		iterator it(array);
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		iterator it2(array + 4);
		write_result(ofs, it[3]);
		it += 3;
		write_result(ofs, it[3]);

		it -= 1;
		write_result(ofs, it[3]);
		it -= 2;
		write_result(ofs, it[3]);
	}
}
