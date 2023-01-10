#include "../common/vector_common.cpp"

std::string testName("clear");

template <typename T>
void test_for_type(CURRENT_NAMESPACE::vector<T>& vector1, const T& value);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::vector<int> v1(10, 0);
	test_for_type<int>(v1, 1);

	CURRENT_NAMESPACE::vector<double> v2(50, 42.424242f);
	test_for_type<double>(v2, 1);

	CURRENT_NAMESPACE::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	test_for_type<TestStruct>(v3, TestStruct(1, 1, "1"));


	ofs.close();
}

template <typename T>
void test_for_type(CURRENT_NAMESPACE::vector<T>& vector1, const T& value)
{
	{ // clear empty vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		v.clear();
		write_result(ofs, v);
	}
	{ // clear filled vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.clear();
		write_result(ofs, v);
	}
	{ // clear filled vector then re-assign it
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.clear();
		v.assign(vector1.begin(), vector1.end());
		write_result(ofs, v);
	}
	{ // clear vector multiple times
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.clear();
		v.clear();
		v.clear();
		write_result(ofs, v);
	}
	{ // clear vector, reserve then re-clear
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.clear();
		v.reserve(20);
		v.clear();
		write_result(ofs, v);
	}
	{ // checking iterators validity
		TEST_INIT();
		typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
		CURRENT_NAMESPACE::vector<T> v(10, value);
		iterator it1 = v.begin();
		iterator it2 = v.end();
		v.clear();
		write_result(ofs, v);
		write_result(ofs, it1 == v.begin());
		write_result(ofs, it2 == v.end());
	}
}
