#include "../common/map_common.cpp"

std::string testName = "copy_constructor";
template <class T, class U, class C>
void test_for_type(CURRENT_NAMESPACE::map<T, U, C> &map);

int main(void)
{
    INIT_SIGNAL();
    CURRENT_NAMESPACE::map<int, int> m_int;
    CURRENT_NAMESPACE::map<double, char> m_double;
    CURRENT_NAMESPACE::map<std::string, int> m_string;
    CURRENT_NAMESPACE::map<TestStruct, TestStruct> m_struct;
    CURRENT_NAMESPACE::map<TestStruct, double> m_struct2;
    CURRENT_NAMESPACE::map<int, int, ft_greater<int> > m_int_comp;
    CURRENT_NAMESPACE::map<double, char, ft_greater<double> > m_double_comp;
    CURRENT_NAMESPACE::map<std::string, int, ft_greater<std::string> > m_string_comp;
    CURRENT_NAMESPACE::map<TestStruct, TestStruct, ft_greater<TestStruct> > m_struct_comp;
    CURRENT_NAMESPACE::map<TestStruct, double, ft_greater<TestStruct> > m_struct2_comp;

    for(int i = 0; i < 1500; i++)
    {
        m_int.insert(CURRENT_NAMESPACE::pair<int, int>(i, i));
        m_int_comp.insert(CURRENT_NAMESPACE::pair<int, int>(i, i));
        m_double.insert(CURRENT_NAMESPACE::pair<double, char>(i, i % 127));
        m_double_comp.insert(CURRENT_NAMESPACE::pair<double, char>(i, i % 127));
        m_string.insert(CURRENT_NAMESPACE::pair<std::string, int>(std::to_string(i), i));
        m_string_comp.insert(CURRENT_NAMESPACE::pair<std::string, int>(std::to_string(i), i));
        m_struct.insert(CURRENT_NAMESPACE::pair<TestStruct, TestStruct>(TestStruct(i, i, std::to_string(i)), TestStruct(i, i, std::to_string(i))));
        m_struct_comp.insert(CURRENT_NAMESPACE::pair<TestStruct, TestStruct>(TestStruct(i, i, std::to_string(i)), TestStruct(i, i, std::to_string(i))));
        m_struct2.insert(CURRENT_NAMESPACE::pair<TestStruct, double>(TestStruct(i, i, std::to_string(i)), i));
        m_struct2_comp.insert(CURRENT_NAMESPACE::pair<TestStruct, double>(TestStruct(i, i, std::to_string(i)), i));
    }

    test_for_type<int, int, std::less<int> >(m_int);
    test_for_type<double, char, std::less<double> >(m_double);
    test_for_type<std::string, int, std::less<std::string> >(m_string);
    test_for_type<TestStruct, TestStruct, std::less<TestStruct> >(m_struct);
    test_for_type<TestStruct, double, std::less<TestStruct> >(m_struct2);
    test_for_type<int, int, ft_greater<int> >(m_int_comp);
    test_for_type<double, char, ft_greater<double> >(m_double_comp);
    test_for_type<std::string, int, ft_greater<std::string> >(m_string_comp);
    test_for_type<TestStruct, TestStruct, ft_greater<TestStruct> >(m_struct_comp);
    test_for_type<TestStruct, double, ft_greater<TestStruct> >(m_struct2_comp);

    ofs.close();
}

template <class T, class U, class C>
void test_for_type(CURRENT_NAMESPACE::map<T, U, C> &map)
{
    TEST_INIT();
    CURRENT_NAMESPACE::map<T, U, C> m(map);
    CURRENT_NAMESPACE::map<T, U, C> m1(map);
    CURRENT_NAMESPACE::map<T, U, C> m2(m1);
	write_result(ofs, m, true);
	write_result(ofs, m1, true);
	write_result(ofs, m2, true);

}
