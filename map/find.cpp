#include "../common/map_common.cpp"

std::string testName = "find";

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
		iterator it = m.find(T());
		write_result(ofs, it == m.end());
		write_result(ofs, it == m.begin());
	}
	{ // Find with filled map
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, U>m;
		T key = T();
		U value = U();
		for (int i = 0; i < 15; i++)
		{
			iterator it;
			m.insert(CURRENT_NAMESPACE::pair<T, U>(key, value));
			it = m.find(key);
			if (it != m.end())
				write_result(ofs, *it);
			else
				write_result(ofs, it == m.end());

			++key;
			++value;
			if (it != m.end())
				write_result(ofs, *it);
			else
				write_result(ofs, it == m.end());
		}
	}
}

template <class T, class U>
void const_map(const CURRENT_NAMESPACE::map<T, U>& m)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	{ // Find with unitialized const map
		TEST_INIT();
		const_iterator it = m.find(T());
		write_result(ofs, it == m.end());
		write_result(ofs, it == m.begin());
	}
	{ // Find with filled const map
		TEST_INIT();
		const_iterator it1 = m.begin();

		T key = T();
		while (it1 != m.end())
		{
			const_iterator it2 = m.find(key);
			if (it2 != m.end())
				write_result(ofs, *it2);
			else
				write_result(ofs, it2 == m.end());
			++key;
			it1++;
		}
		it1 = m.find(key);
		write_result(ofs, it1 == m.end());
	}
}
