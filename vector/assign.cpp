#include "../common/vector_common.cpp"

std::string testName("assign");

template <typename T>
void test_for_type(const T& value);

template <typename T>
void test_assign_fill_version(const T& value);

template <typename T>
void test_assign_range_version(CURRENT_NAMESPACE::vector<T>& v);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(10);
	test_for_type<TestStruct>(TestStruct(42, 10, "crampon"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	test_assign_fill_version<T>(value);

	CURRENT_NAMESPACE::vector <T> v(10, value);
	test_assign_range_version<T>(v);
}

template <typename T>
void test_assign_fill_version(const T& value)
{
	{ // simple assign
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		v.assign(5, value);
		write_result(ofs, v);
	}
	{ // assign with count = 0
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		v.assign(0, value);
		write_result(ofs, v);
	}
	{ // Assign with existing values in vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.assign(10, value * 2);
		write_result(ofs, v);
	}
	{ // Assign with existing values in vector + new size lower
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.assign(5, value * 2);
		write_result(ofs, v);
	}
	{ // Assign with existing values in vector + new size greater
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(10, value);
		v.assign(20, value * 2);
		write_result(ofs, v);
	}
}

template <typename T>
void test_assign_range_version(CURRENT_NAMESPACE::vector<T>& v)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::vector<T>::const_iterator const_iterator;

	{ // Assign with vector iterators
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector;
		vector.assign(v.begin(), v.end());
		write_result(ofs, vector);
	}
	{ // Assign with vector const iterator
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector;
		vector.assign(v.begin(), v.end());
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators and modified range
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector;
		vector.assign(v.begin() + v.size() / 4, v.end() - v.size() / 4);
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators which are both equal
		TEST_INIT();
		const_iterator cit = v.begin() + 2;
		CURRENT_NAMESPACE::vector<T> vector;
		vector.assign(cit, cit);
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators and existing values
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector(5, v[0] * 2);
		vector.assign(v.begin(), v.end());
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators (modified range)  and existing values
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector(5, v[0] * 2);
		vector.assign(v.begin() + v.size() / 4, v.end() - v.size() / 4);
		write_result(ofs, vector);
	}

}
