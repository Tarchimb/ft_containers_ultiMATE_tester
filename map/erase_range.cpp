#include "../common/map_common.cpp"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

std::string testName = "erase_range";
template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map);

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

	test_for_type<double, char>(m_double);
	test_for_type<std::string, int>(m_string);
	test_for_type<TestStruct, TestStruct>(m_struct);
	test_for_type<TestStruct, double>(m_struct2);

	ofs.close();
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map)
{
	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	typedef typename CURRENT_NAMESPACE::map<T, U>::size_type size_type;
	{ //Erase whole map
		TEST_INIT();
        CURRENT_NAMESPACE::map<T, U> m(map);
        iterator it = m.begin(), end = m.end();
        m.erase(it, end);
        write_result(ofs, m);
	}
	{ //Erase from begin to middle
		TEST_INIT();
        CURRENT_NAMESPACE::map<T, U> m(map);
        iterator it = m.begin(), end = m.begin();
        std::advance(end, m.size() / 2);
        m.erase(it, end);
        write_result(ofs, m);
	}
	{ //Erase from middle to end
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin(), end = m.end();
			std::advance(it, m.size() / 2);
			m.erase(it, end);
			write_result(ofs, m);
	}
	{ //Erase the middle
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin(), end = m.end();
			std::advance(it, 10);
			std::advance(end, -10);
			m.erase(it, end);
			write_result(ofs, m);
	}
	{ //Erase range of 1
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin(), end = m.begin();
			std::advance(end, 1);
			m.erase(it, end);
			write_result(ofs, m);
	}
	{ //Erase range of 2
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin(), end = m.begin();
			std::advance(end, 2);
			m.erase(it, end);
			write_result(ofs, m);
	}
	{ //Multiple erase
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin(), end = m.begin();
			std::advance(end, 10);
			m.erase(it, end);
			write_result(ofs, m);
			it = m.begin(), end = m.begin();
			std::advance(end, 10);
			m.erase(it, end);
			write_result(ofs, m);
			it = m.begin(), end = m.begin();
			std::advance(end, 10);
			m.erase(it, end);
			write_result(ofs, m);
	}
	{ //Multiple erase of 1
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin(), end = m.begin();
			std::advance(end, 1);
			m.erase(it, end);
			write_result(ofs, m);
			it = m.begin(), end = m.begin();
			std::advance(end, 1);
			m.erase(it, end);
			write_result(ofs, m);
			it = m.begin(), end = m.begin();
			std::advance(end, 1);
			m.erase(it, end);
			write_result(ofs, m);
	}
}
