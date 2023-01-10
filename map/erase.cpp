#include "../common/map_common.cpp"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

std::string testName = "erase";
template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map);

int main(int argc, char** argv)
{
    INIT_SIGNAL();
    CURRENT_NAMESPACE::map<int, int> m_int;
    CURRENT_NAMESPACE::map<double, char> m_double;
    CURRENT_NAMESPACE::map<std::string, int> m_string;
    CURRENT_NAMESPACE::map<TestStruct, TestStruct> m_struct;
    CURRENT_NAMESPACE::map<TestStruct, double> m_struct2;


    for(int i = 0; i < 150; i++)
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
	{ //Delete by pos with iterator
		TEST_INIT();
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin();
			m.erase(it);
			it = m.end();
			it--;
			m.erase(it);
			it = m.begin();
			m.erase(it);
			write_result(ofs, m);
    }
    { //Delete by pos with const_iterator
		TEST_INIT();
			const_iterator it = map.begin();
			map.erase(it);
			it = map.begin();
			map.erase(it);
			it = map.begin();
			map.erase(it);
			write_result(ofs, map);
    }
}
