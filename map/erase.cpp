#include "../map_common.cpp"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

std::string testName = "erase";
template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map, CURRENT_NAMESPACE::pair<T, U> val);

int main(void)
{
    CURRENT_NAMESPACE::map<int, int> m_int;
    CURRENT_NAMESPACE::map<double, char> m_double;
    CURRENT_NAMESPACE::map<std::string, int> m_string;
    CURRENT_NAMESPACE::map<TestStruct, TestStruct> m_struct;
    CURRENT_NAMESPACE::map<TestStruct, double> m_struct2;


    for(int i = 0; i < 10; i++)
    {
        m_int.insert(CURRENT_NAMESPACE::pair<int, int>(i, i));
        m_double.insert(CURRENT_NAMESPACE::pair<double, char>(i, i % 127));
        m_string.insert(CURRENT_NAMESPACE::pair<std::string, int>(std::to_string(i), i));
        m_struct.insert(CURRENT_NAMESPACE::pair<TestStruct, TestStruct>(TestStruct(i, i, std::to_string(i)), TestStruct(i, i, std::to_string(i))));
        m_struct2.insert(CURRENT_NAMESPACE::pair<TestStruct, double>(TestStruct(i, i, std::to_string(i)), i));
    }

    test_for_type<double, char>(m_double, CURRENT_NAMESPACE::pair<double, char>(42, 42 % 127));
    test_for_type<std::string, int>(m_string, CURRENT_NAMESPACE::pair<std::string, int>(std::to_string(42), 42));
    test_for_type<TestStruct, TestStruct>(m_struct, CURRENT_NAMESPACE::pair<TestStruct, TestStruct>(TestStruct(42, 42, std::to_string(42)), TestStruct(42, 42, std::to_string(42))));
    test_for_type<TestStruct, double>(m_struct2, CURRENT_NAMESPACE::pair<TestStruct, double>(TestStruct(42, 42, std::to_string(42)), 42));

    ofs.close();
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U> &map, CURRENT_NAMESPACE::pair<T, U> val)
{
    typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
    typedef typename CURRENT_NAMESPACE::map<T, U>::const_iterator const_iterator;
	{ //Delete by pos with iterator
		TEST_INIT()
		{
			CURRENT_NAMESPACE::map<T, U> m(map);
			iterator it = m.begin();
			m.erase(it);
			it = m.end();
			it--;
			m.erase(it);
			it = m.begin();
			m.erase(it);
			exit(0);
		}
    }
    { //Delete by pos with const_iterator
		TEST_INIT()
		{
			const_iterator it = map.begin();
			map.erase(it);
			it = map.begin();
			map.erase(it);
		}
    }
	{ //Erase whole map forward
		TEST_INIT()
		{
//			CURRENT_NAMESPACE::map<T, U> m(map);
			while (map.size() > 0) {
				iterator it = map.begin();
				map.erase(it);
			}
			exit(0);
		}
    }
    { //Erase whole map backward
        TEST_INIT()
		{
        for (iterator it = map.end(); it != map.begin(); it--)
            map.erase(it);
			exit(0);
		}
	}
//    }

}
