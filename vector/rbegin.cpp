#include "../common/vector_common.cpp"

std::string testName("rbegin");

template <typename T>
void test_for_type(std::ofstream& ofs, CURRENT_NAMESPACE::vector<T>& vector1);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(ofs, v1);

	CURRENT_NAMESPACE::vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(ofs, v2);

	CURRENT_NAMESPACE::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(ofs, v3);

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, CURRENT_NAMESPACE::vector<T>& vector1)
{
	TEST_INIT();

	typename CURRENT_NAMESPACE::vector<T>::const_reverse_iterator it = vector1.rbegin();
	write_result<T>(ofs, *it);
	typename CURRENT_NAMESPACE::vector<T>::reverse_iterator it2 = vector1.rbegin();
	write_result<T>(ofs, (*it2));
	write_result<bool>(ofs, &(*it2) == &(*it));
}
