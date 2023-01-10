#include "../common/map_common.cpp"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

std::string testName = "erase_key";
template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map, typename CURRENT_NAMESPACE::pair<T, U>::first_type key, typename CURRENT_NAMESPACE::pair<T, U>::first_type wrong_key);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::map<int, int> m_int;
	CURRENT_NAMESPACE::map<double, char> m_double;
	CURRENT_NAMESPACE::map<std::string, int> m_string;
	CURRENT_NAMESPACE::map<TestStruct, TestStruct> m_struct;
	CURRENT_NAMESPACE::map<TestStruct, double> m_struct2;


	for(int i = 0; i < 50; i++)
	{
		m_int.insert(CURRENT_NAMESPACE::pair<int, int>(i, i));
		m_double.insert(CURRENT_NAMESPACE::pair<double, char>(i, i % 127));
		m_string.insert(CURRENT_NAMESPACE::pair<std::string, int>(std::to_string(i), i));
		m_struct.insert(CURRENT_NAMESPACE::pair<TestStruct, TestStruct>(TestStruct(i, i, std::to_string(i)), TestStruct(i, i, std::to_string(i))));
		m_struct2.insert(CURRENT_NAMESPACE::pair<TestStruct, double>(TestStruct(i, i, std::to_string(i)), i));
	}

	test_for_type<double, char>(m_double, 42, 84);
	test_for_type<std::string, int>(m_string, "42", "84");
	test_for_type<TestStruct, TestStruct>(m_struct,TestStruct(42, 42, std::to_string(42)), TestStruct(84, 84, std::to_string(84)));
	test_for_type<TestStruct, double>(m_struct2,TestStruct(42, 42, std::to_string(42)), TestStruct(84, 84, std::to_string(84)));

	ofs.close();
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map, typename CURRENT_NAMESPACE::pair<T, U>::first_type key, typename CURRENT_NAMESPACE::pair<T, U>::first_type wrong_key)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::size_type size_type;
	{ //Erase existing key
		TEST_INIT();
        CURRENT_NAMESPACE::map<T, U> m(map);
        m.erase(key);
        write_result(ofs, m);
	}
	{ //Erase same key two times
		TEST_INIT();
        CURRENT_NAMESPACE::map<T, U> m(map);
        m.erase(key);
        m.erase(key);
        write_result(ofs, m);
	}
	{ //Erase same key n times
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			for (int i = 0; i < 100; i++)
				m.erase(key);
			write_result(ofs, m);
	}
	{ //Erase non-existing key
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			m.erase(wrong_key);
			write_result(ofs, m);
	}
	{ // Erase whole map forward
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it;
			for (size_type i = 0; i < m.size(); i++)
			{
				it = m.begin();
				m.erase(it->first);
			}
			write_result(ofs, m);
	}
	{ // Erase whole map backward
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it;
			for (size_type i = 0; i < m.size(); i++)
			{
				it = m.end();
				it--;
				m.erase(it->first);
			}
			write_result(ofs, m);
	}
}
