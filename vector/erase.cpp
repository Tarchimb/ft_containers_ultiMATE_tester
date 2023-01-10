#include "../common/vector_common.cpp"

std::string testName("erase");

template <typename T>
void test_for_type(const T& value);

// CHANGE FIRST OVERLOAD WITH OVERLOAD NAME (MORE EXPLICIT NAMES)
// RELY ON MORE DEFINE (REMOVE HARD CODED VALUES IN MAIN)
// ADD VECTOR T TYPEDEF IN COMMON
// TIMER ?

template <typename T>
void test_erase_position(const T& value);
template <typename T>
void test_erase_range(const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(10);
	test_for_type<float>(10.5f);
	test_for_type<double>(10.5f);
	test_for_type<TestStruct>(TestStruct(5, -42, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	test_erase_position<T>(value);
	test_erase_range<T>(value);
}

template <typename T>
void test_erase_position(const T& value)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;

	{ // erase value at vector beginning
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.begin());
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase value in vector middle
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.begin() + 2);
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase the only value in vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(1, value);
		iterator it = v.erase(v.begin());
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase value at the end
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.end() - 1);
		write_result(ofs, v);
		write_result(ofs, *it);
		write_result(ofs, &(*it) == &(*v.end()));
	}
	{ // erase value on only reserved vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(1);
		iterator it = v.erase(v.begin());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
}

template <typename T>
void test_erase_range(const T& value)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	{ // erase whole vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.begin(), v.end());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase vector (begin & end not included)
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.begin() + 1, v.end() - 1);
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase whole vector except begin
		TEST_INIT();

		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.begin() + 1, v.begin() + v.size());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase vector except the last three elements
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.end() - 3, v.end());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
	{ // erase with begin and end are equals
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator it = v.erase(v.begin(), v.begin());
		write_result(ofs, v);
		write_result(ofs, &(*it) == &(*v.begin()));
	}
}
