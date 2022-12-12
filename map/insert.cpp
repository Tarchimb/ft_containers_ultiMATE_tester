#include "../map_common.cpp"
#include <cstdlib>
#include <utility>

std::string testName = "insert";

template <class T, class U>
void test_pair(CURRENT_NAMESPACE::map<T, U> map, T key, U value);

// int arr_int[50] = {71, 87, 70, 22, 28, 2, 43, 99, 32, 46, 76, 69, 51, 36, 19, 42, 86, 10, 62, 20, 49, 29, 64, 56, 67, 15, 38, 12, 57, 55, 60, 26, 96, 83, 25, 47, 3, 100, 11, 5, 66, 91, 23, 63, 24, 85, 4, 53, 34, 28};
// int arr_int_size = 50;

int main(void)
{
	TEST_INIT();

	CURRENT_NAMESPACE::map<int, int> m;
	test_pair<int, int>(m, -3, 1);
	test_pair<int, int>(m, 10, 1);
	test_pair<int, int>(m, 5, 1);
	test_pair<int, int>(m, 0, 1);
	test_pair<int, int>(m, -3, 2);
	test_pair<int, int>(m, 10, 1);

	CURRENT_NAMESPACE::map<std::string, int> m2;
	test_pair<std::string, int>(m2, "ALED", 1);
	test_pair<std::string, int>(m2, "AELD", 1);
	test_pair<std::string, int>(m2, "ADEL", 1);
	test_pair<std::string, int>(m2, "EALD", 1);
	test_pair<std::string, int>(m2, "ALED", 2);
	test_pair<std::string, int>(m2, "LADE", 1);
	

	ofs.close();
}

template <class T, class U>
void test_pair(CURRENT_NAMESPACE::map<T, U> map, T key, U value)
{
	TEST_INIT();

	typedef typename CURRENT_NAMESPACE::map<T, U>::iterator iterator;
	CURRENT_NAMESPACE::pair<iterator, bool> pair;

	pair = map.insert(CURRENT_NAMESPACE::make_pair(key, value));
	ofs << pair.first->first << ", " << pair.second << std::endl; 
	write_result(ofs, map);
}
