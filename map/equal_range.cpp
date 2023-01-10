#include "../common/map_common.cpp"

std::string testName = "equal_range";

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
	{ // Equal range with unitialized map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m;
		CURRENT_NAMESPACE::pair<iterator, iterator> p = m.equal_range(T());
		write_result(ofs, p.first == m.end());
		write_result(ofs, p.second == m.end());
	}
	{ // Equal range with filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m;
		T key = T();
		U value = U();
		for (int i = 0; i < 15; i++)
		{
			iterator it;
			m.insert(CURRENT_NAMESPACE::pair<T, U>(key, value));
			CURRENT_NAMESPACE::pair<iterator, iterator> p = m.equal_range(key);
			if (p.first == m.end())
				write_result(ofs, p.first == m.end());
			else
				write_result(ofs, *(p.first));
			if (p.second == m.end())
				write_result(ofs, p.second == m.end());
			else
				write_result(ofs, *(p.second));

			++key;
			++value;
			write_result(ofs, p.first == m.end());
			write_result(ofs, p.second == m.end());
		}
	}
}

template <class T, class U>
void const_map(const CURRENT_NAMESPACE::map<T, U>& m)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	{ // Equal range with unitialized const map
		TEST_INIT();
		CURRENT_NAMESPACE::pair<const_iterator, const_iterator> p = m.equal_range(T());
		write_result(ofs, p.first == m.end());
		write_result(ofs, p.second == m.end());
	}
	{ // Equal range with filled const map
		TEST_INIT();
		const_iterator it1 = m.begin();

		T key = T();
		while (it1 != m.end())
		{
			CURRENT_NAMESPACE::pair<const_iterator, const_iterator> p = m.equal_range(key);
			if (p.first == m.end())
				write_result(ofs, p.first == m.end());
			else
				write_result(ofs, *(p.first));
			if (p.second == m.end())
				write_result(ofs, p.second == m.end());
			else
				write_result(ofs, *(p.second));
			++key;
			it1++;
			write_result(ofs, p.first == m.end());
			write_result(ofs, p.second == m.end());
		}
		it1 = m.find(key);
		write_result(ofs, it1 == m.end());
	}
}
