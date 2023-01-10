#include "../common/vector_common.cpp"

std::string testName("resize");

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(ofs, 10);
	test_for_type<float>(ofs, 10.5f);
	test_for_type<TestStruct>(ofs, TestStruct(5, -42, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value)
{
	typedef typename CURRENT_NAMESPACE::vector<T>::iterator iterator;
	{ // resize normal value with empty vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v;
		v.clear();
		v.resize(5);
		write_result(ofs, v);
	}
	{ // resize less than currently reserved
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(50);
		v.resize(5);
		write_result(ofs, v);
	}
	{ // resize 0
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		v.resize(0);
		write_result(ofs, v);
	}
	{ // multiple resize
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		v.resize(5);
		v.resize(5);
		v.resize(9);
		v.resize(9);
		v.resize(2);
		v.resize(2);
		write_result(ofs, v);
	}
	{ // resize more than currently reserved
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		v.resize(100);
		write_result(ofs, v);
	}
	{ // resize more than currently reserved with large size
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		v.resize(10000);
		write_result(ofs, v);
	}
	{ // resize more than vector max size
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		try {
			v.resize(v.max_size() + 1);
		} catch ( const std::exception& e) {
			write_result(ofs, "vector thrown with too large resize");
		}
	}
	{ // resize with exact vector size
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> v(5, value);
		iterator begin = v.begin();
		iterator end = v.end();
		v.resize(v.size());
		write_result(ofs, v);
		write_result(ofs, begin == v.begin());
		write_result(ofs, end == v.end());
	}
}
