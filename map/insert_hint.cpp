#include "../common/map_common.cpp"
#include <cstdlib>
#include <ios>
#include <iterator>
#include <utility>

std::string testName = "insert_hint";

template <class T, class U, class C>
void test_pair(CURRENT_NAMESPACE::map<T, U> &map, T key, U value, C &it);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::map<int, int> m;
	typedef CURRENT_NAMESPACE::map<int, int>::iterator iterator;
	iterator it = m.end();
	test_pair<int, int, iterator>(m, 1, 1, it);
	it = m.begin();
	test_pair<int, int, iterator>(m, -10, 1, it);
	std::advance(it, 1);
	test_pair<int, int, iterator>(m, 12, 1, it);
	it = m.end();
	test_pair<int, int, iterator>(m, 0, 1, it);
	test_pair<int, int, iterator>(m, 1, 2, it);
	it = m.begin();
	std::advance(it, 3);
	test_pair<int, int, iterator>(m, -5, 1, it);

	CURRENT_NAMESPACE::map<std::string, int> m2;
	typedef CURRENT_NAMESPACE::map<std::string, int>::iterator iterator1;
	iterator1 it1 = m2.end();
	test_pair<std::string, int, iterator1>(m2, "ALED", 1, it1);
	it1 = m2.begin();
	test_pair<std::string, int, iterator1>(m2, "BAELD", 1, it1);
	std::advance(it1, 1);
	test_pair<std::string, int, iterator1>(m2, "ADEL", 1, it1);
	it1 = m2.end();
	test_pair<std::string, int, iterator1>(m2, "EALD", 1, it1);
	test_pair<std::string, int, iterator1>(m2, "ALED", 2, it1);
	it1 = m2.begin();
	std::advance(it1, 3);
	test_pair<std::string, int, iterator1>(m2, "LADE", 1, it1);

	CURRENT_NAMESPACE::map<TestStruct, int> m3;
	typedef CURRENT_NAMESPACE::map<TestStruct, int>::iterator iterator2;
	iterator2 it2 = m3.end();
	test_pair<TestStruct, int, iterator2>(m3, TestStruct(1, 1, "a"), 1, it2);
	it2 = m3.begin();
	test_pair<TestStruct, int, iterator2>(m3, TestStruct(-10, 2, "b"), 1, it2);
	std::advance(it2, 1);
	test_pair<TestStruct, int, iterator2>(m3, TestStruct(12, 3, "c"), 1, it2);
	test_pair<TestStruct, int, iterator2>(m3, TestStruct(0, 4, "d"), 1, it2);
	it2 = m3.end();
	test_pair<TestStruct, int, iterator2>(m3, TestStruct(1, 1, "a"), 2, it2);
	it2 = m3.begin();
	std::advance(it2, 3);
	test_pair<TestStruct, int, iterator2>(m3, TestStruct(-5, 6, "f"), 1, it2);

	ofs.close();
}

template <class T, class U, class C>
void test_pair(CURRENT_NAMESPACE::map<T, U> &map, T key, U value, C &it)
{// Insert the pair with hint and check the return value
	TEST_INIT();

	C	it1;

	it1 = map.insert(it, CURRENT_NAMESPACE::make_pair(key, value));
	if (it != map.end())
		ofs << it->first << ", " << it->second << std::endl;
	else
		ofs << "END NODE" << std::endl;
	write_result(ofs, map);
}
