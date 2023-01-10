#include "../common/map_common.cpp"

std::string testName = "range_constructor";

template <class T, class U, class C = std::less<T> >
void test_for_type(CURRENT_NAMESPACE::map<T, U, C> &map);

int main(void)
{
    INIT_SIGNAL();
    CURRENT_NAMESPACE::map<int, int> m_int = generate_map<int, int>(50);
    CURRENT_NAMESPACE::map<double, char> m_double = generate_map<double, char>(50);
    CURRENT_NAMESPACE::map<TestStruct, TestStruct> m_struct = generate_map<TestStruct, TestStruct>(50);
    CURRENT_NAMESPACE::map<TestStruct, double> m_struct2 = generate_map<TestStruct, double>(50);
    CURRENT_NAMESPACE::map<int, int, ft_greater<int> > m_int_comp = generate_map<int, int, ft_greater<int> >(50);
    CURRENT_NAMESPACE::map<double, char, ft_greater<double> > m_double_comp = generate_map<double, char, ft_greater<double> >(50);
    CURRENT_NAMESPACE::map<TestStruct, TestStruct, ft_greater<TestStruct> > m_struct_comp = generate_map<TestStruct, TestStruct, ft_greater<TestStruct> >(50);
    CURRENT_NAMESPACE::map<TestStruct, double, ft_greater<TestStruct> > m_struct2_comp = generate_map<TestStruct, double, ft_greater<TestStruct> >(50);

    test_for_type<int, int, std::less<int> >(m_int);
    test_for_type<double, char, std::less<double> >(m_double);
    test_for_type<TestStruct, TestStruct, std::less<TestStruct> >(m_struct);
    test_for_type<TestStruct, double, std::less<TestStruct> >(m_struct2);
    test_for_type<int, int, ft_greater<int> >(m_int_comp);
    test_for_type<double, char, ft_greater<double> >(m_double_comp);
    test_for_type<TestStruct, TestStruct, ft_greater<TestStruct> >(m_struct_comp);
    test_for_type<TestStruct, double, ft_greater<TestStruct> >(m_struct2_comp);
    ofs.close();
}

template <class T, class U, class C>
void test_for_type(CURRENT_NAMESPACE::map<T, U, C> &map)
{
    { // Simple construct range
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U, C> m(map.begin(), map.end());
        write_result(ofs, m, true);
    }
    { // Construct from an empty range
        TEST_INIT();
        CURRENT_NAMESPACE::map<T, U, C> m_empty;
        CURRENT_NAMESPACE::map<T, U, C> m(m_empty.begin(), m_empty.end());
        write_result(ofs, m, true);
    }
}
