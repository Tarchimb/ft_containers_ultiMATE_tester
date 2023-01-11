#include "../common/map_common.cpp"

std::string testName("random");

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& m, T key, U value);

int main(void)
{
    INIT_SIGNAL();
    CURRENT_NAMESPACE::map<int, int> m = generate_map<int, int>(20);
    test_for_type<int, int>(m, 42, 42);

    CURRENT_NAMESPACE::map<double, TestStruct> m1 = generate_map<double, TestStruct>(50);
    test_for_type<double, TestStruct>(m1, 42.42, TestStruct(42, 42.42, "42"));

    CURRENT_NAMESPACE::map<TestStruct, TestStruct> m2 = generate_map<TestStruct, TestStruct>(50);
    test_for_type<TestStruct, TestStruct>(m2, TestStruct(42, 42.42, "42"), TestStruct(42, 42.42, "42"));
    ofs.close();
}

template <class T, class U>
void test_for_type(CURRENT_NAMESPACE::map<T, U>& m, T key, U value)
{
    { //Insert and erase
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U>    map(m);
        map.erase(map.begin(), map.end());
        write_result(ofs, map);
        for (int i = 0; i < 20; i++) {
            map.insert(CURRENT_NAMESPACE::make_pair(++key, ++value));
        }
        write_result(ofs, map);
        map.insert(map.end(), CURRENT_NAMESPACE::make_pair(key, value));
        write_result(ofs, map);
        map.erase(map.begin(), map.end());
        write_result(ofs, map);
    }
    { // iterator tests
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U>    map(m);
        typename CURRENT_NAMESPACE::map<T, U>::iterator it = map.begin();

        it == map.end() ? write_result(ofs, "END") : write_result(ofs, *it);
        it = map.find(key);
        it == map.end() ? write_result(ofs, "END") : write_result(ofs, *it);
        it = map.insert(it, CURRENT_NAMESPACE::make_pair(key, value));
        it == map.end() ? write_result(ofs, "END") : write_result(ofs, *it);
        it = map.lower_bound(key);
        it == map.end() ? write_result(ofs, "END") : write_result(ofs, *it);
        it = map.upper_bound(key);
        it == map.end() ? write_result(ofs, "END") : write_result(ofs, *it);
    }
    { //modifier tests
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U>    map(m);
        CURRENT_NAMESPACE::map<T, U>    map1(m);

        map.swap(map1);
        write_result(ofs, map);
        write_result(ofs, map1);
        map.insert(map1.begin(), map1.end());
        map.swap(map1);
        map.erase(map.begin(), map.end());
        write_result(ofs, map);
        map.swap(map1);
        write_result(ofs, map1);
        write_result(ofs, map);
        map.clear();
        write_result(ofs, map);
    }
}