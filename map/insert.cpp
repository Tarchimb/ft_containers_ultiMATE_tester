#include "../common/map_common.cpp"
#include <cstdlib>
#include <utility>

std::string testName = "insert";

template <class T, class U>
void test_pair(CURRENT_NAMESPACE::map<T, U> &map, T key, U value);

int main(void)
{
	CURRENT_NAMESPACE::map<int, int> m;
	test_pair<int, int>(m, 1, 1);
	test_pair<int, int>(m, -10, 1);
	test_pair<int, int>(m, 12, 1);
	test_pair<int, int>(m, 0, 1);
	test_pair<int, int>(m, 1, 2);
	test_pair<int, int>(m, -5, 1);

	CURRENT_NAMESPACE::map<std::string, int> m2;
	test_pair<std::string, int>(m2, "ALED", 1);
	test_pair<std::string, int>(m2, "AELD", 1);
	test_pair<std::string, int>(m2, "ADEL", 1);
	test_pair<std::string, int>(m2, "EALD", 1);
	test_pair<std::string, int>(m2, "ALED", 2);
	test_pair<std::string, int>(m2, "LADE", 1);

	CURRENT_NAMESPACE::map<TestStruct, int> m3;
	test_pair<TestStruct, int>(m3, TestStruct(1, 1, "a"), 1);
	test_pair<TestStruct, int>(m3, TestStruct(-10, 2, "b"), 1);
	test_pair<TestStruct, int>(m3, TestStruct(12, 3, "c"), 1);
	test_pair<TestStruct, int>(m3, TestStruct(0, 4, "d"), 1);
	test_pair<TestStruct, int>(m3, TestStruct(1, 1, "a"), 2);
	test_pair<TestStruct, int>(m3, TestStruct(-5, 6, "f"), 1);
	
	ofs.close();
}

template <class T, class U>
void test_pair(CURRENT_NAMESPACE::map<T, U> &map, T key, U value)
{// Insert the pair and check the return value
	TEST_INIT();

	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	CURRENT_NAMESPACE::pair<iterator, bool> pair;

	pair = map.insert(CURRENT_NAMESPACE::make_pair(key, value));
	ofs << pair.first->first << ", " << pair.second << std::endl; 
	write_result(ofs, map);
}
