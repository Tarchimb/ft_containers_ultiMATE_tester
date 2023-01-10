#include "../common/map_common.cpp"
#include <utility>

std::string testName("key_comp");

template <typename T>
void testKeyComp(T tab[3]);

int main()
{
    INIT_SIGNAL();
	int tab[3] = {10, 5, 15};
	testKeyComp<int>(tab);

	char tab1[3] = {'a', 'A', ';'};
    testKeyComp<char>(tab1);

	std::string tab2[3] = {"aled", "ALED", ";*&(#%)"};
    testKeyComp<std::string>(tab2);

	TestStruct tab3[3] = {TestStruct(10, 10, "AB"), TestStruct(5, 5, "AB"), TestStruct(15, 15, "AB")};
    testKeyComp<TestStruct>(tab3);
}

template <typename T>
void testKeyComp(T tab[3])
{
	{
		TEST_INIT();
		CURRENT_NAMESPACE::map<T, int> m2;
		m2.insert(CURRENT_NAMESPACE::make_pair(tab[0], 100));
		m2.insert(CURRENT_NAMESPACE::make_pair(tab[1], 50));
		m2.insert(CURRENT_NAMESPACE::make_pair(tab[2], 150));

		ofs << (m2.key_comp()(tab[0], tab[1]) == false) << std::endl;
		ofs << (m2.key_comp()(tab[1], tab[2]) == true) << std::endl;
		ofs << (m2.key_comp()(tab[2], tab[0]) == false) << std::endl;
	}
}
