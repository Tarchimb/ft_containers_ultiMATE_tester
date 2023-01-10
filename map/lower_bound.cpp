#include "../common/map_common.cpp"

std::string testName = "lower_bound";

template <class T, class U>
void test_for_type();

template <class T, class U>
void classic_map();

template <class T, class U>
void const_map(const CURRENT_NAMESPACE::map<T, U>& m);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int, int>();
	test_for_type<TestStruct, int>();
	test_for_type<TestStruct, TestStruct>();

	ofs.close();
}

template <class T, class U>
void test_for_type()
{
	classic_map<T, U>();
	const_map<T, U>(generate_map<T, U>(15));
}

template <class T, class U>
void classic_map()
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	{ // Find with unitialized map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m;
		iterator it = m.lower_bound(T());
		write_result(ofs, it == m.end());
		write_result(ofs, it == m.begin());
	}
	{ // Find with filled map (value inserted with no gaps)
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m = generate_map<T, U>(15, true);
		T key = T();
		for (int i = 0; i < 20; i++)
		{
			iterator it;
			it = m.lower_bound(key);
			if (it != m.end())
				write_result(ofs, *it);
			else
				write_result(ofs, it == m.end());
			++key;
		}
	}
	{ // Find with filled map (value inserted with gaps)
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m = generate_map<T, U>(15);
		T key = T();
		for (int i = 0; i < 20; i++)
		{
			iterator it;
			it = m.lower_bound(key);
			if (it != m.end())
				write_result(ofs, *it);
			else
				write_result(ofs, it == m.end());
			++key;
		}
	}
}

template <class T, class U>
void const_map(const CURRENT_NAMESPACE::map<T, U>& m)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	{ // Find with unitialized map
		TEST_INIT();
		const_iterator it = m.lower_bound(T());
		write_result(ofs, it == m.end());
		write_result(ofs, it == m.begin());
	}
	{ // Find with filled map (value inserted with no gaps)
		TEST_INIT();
		T key = T();
		for (int i = 0; i < 20; i++)
		{
			const_iterator it;
			it = m.lower_bound(key);
			if (it != m.end())
				write_result(ofs, *it);
			else
				write_result(ofs, it == m.end());
			++key;
		}
	}
}
