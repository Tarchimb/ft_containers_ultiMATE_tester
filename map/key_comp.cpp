#include "../common/map_common.cpp"
//
std::string testName("key_comp");
//
// template <class T, class U>
// void test_for_type();
//
// int main(int argc, char** argv)
// {
// 	test_for_type<int, int>();
// 	// test_for_type<unsigned char, unsigned char>();
// 	// test_for_type<long, long>();
// 	// test_for_type<float, float>();
// 	// test_for_type<std::string, std::string>();
// 	// test_for_type<TestStruct, TestStruct>();
// 	//
// 	// test_for_type<char, int>();
// 	// test_for_type<unsigned char, char>();
// 	// test_for_type<int, long>();
// 	// test_for_type<long, TestStruct>();
// 	// test_for_type<float, int>();
// 	// test_for_type<std::string, long>();
// 	// test_for_type<TestStruct, unsigned char>();
//
// 	ofs.close();
// }
//
// template <class T, class U>
// void test_for_type()
// {// Test the allocator type
// 	TEST_INIT();
// 	CURRENT_NAMESPACE::map<T, U> m = generate_map<T, U>(10);
// 	write_result(ofs, m.key_comp()(71, 86) == true);
// 	write_result(ofs, m.key_comp()(86, 11) == true);
// 	write_result(ofs, m.key_comp()(71, 86) == true);
// 	write_result(ofs, m.key_comp()(71, 86) == true);
// }

void test_key_comp()
{
	{
		TEST_INIT();
		// Test the basic functionality of key_comp
		CURRENT_NAMESPACE::map<int, int> m;
		m[1] = 2;
		m[3] = 4;
		m[5] = 6;
		ofs << (m.key_comp()(1, 3) == true) << std::endl;
		ofs << (m.key_comp()(3, 5) == true) << std::endl;
		ofs << (m.key_comp()(5, 1) == false) << std::endl;
	}

	{
		TEST_INIT();
		// Test the behavior of key_comp on a map with a custom comparator
		CURRENT_NAMESPACE::map<int, int, std::greater<int> > m2;
		m2[1] = 2;
		m2[3] = 4;
		m2[5] = 6;
		ofs << (m2.key_comp()(1, 3) == false) << std::endl;
		ofs << (m2.key_comp()(3, 5) == false) << std::endl;
		ofs << (m2.key_comp()(5, 1) == true) << std::endl;
	}
}

int main()
{
    test_key_comp();
}
