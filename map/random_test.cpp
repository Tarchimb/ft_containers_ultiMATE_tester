#include "../common/map_common.cpp"

std::string testName("random_test");

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& m, T key, U value);

int main(void)
{
    INIT_SIGNAL();
    CURRENT_NAMESPACE::map<int, int> m = generate_map<int, int>(20);
    test_for_type<int, int>(m, 42, 42);

//    CURRENT_NAMESPACE::map<double, TestStruct> m1 = generate_map<double, TestStruct>(50);
//    test_for_type<double, TestStruct>(m1, 42.42, TestStruct(42, 42.42, "42"));
//
//    CURRENT_NAMESPACE::map<TestStruct, TestStruct> m2 = generate_map<TestStruct, TestStruct>(50);
//    test_for_type<TestStruct, TestStruct>(m2, TestStruct(42, 42.42, "42"), TestStruct(42, 42.42, "42"));
    ofs.close();
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& m, T key, U value)
{
    {
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U>    map(m);
        CURRENT_NAMESPACE::map<T, U>    map2;
        map.insert(CURRENT_NAMESPACE::make_pair(key, value));
        write_result(ofs, map);
        map.erase(map.begin(), map.end());
        write_result(ofs, map);
        for (int i = 0; i < 100; i++)
            map.insert(CURRENT_NAMESPACE::make_pair(++key, ++value));
        write_result(ofs, map);
        map2 = map;
        write_result(ofs, map);
        write_result(ofs, map2);
        map.insert(map.end(), CURRENT_NAMESPACE::make_pair(key, value));
        map.insert(map2.begin(), map2.end());
        write_result(ofs, map);
//        map.erase()
    }
}