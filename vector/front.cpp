#include "../common/vector_common.cpp"

std::string testName("front");

template <typename T>
void test_for_type(CURRENT_NAMESPACE::vector<T>& vector1);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::vector<int> v1(10, 0);
	for (int i = 0; i < v1.size(); i++)
		v1[i] = i;
	test_for_type<int>(v1);

	CURRENT_NAMESPACE::vector<double> v2(1000, 42.424242f);
	for (int i = 0; i < v2.size(); i++)
		v2[i] = i;
	test_for_type<double>(v2);

	CURRENT_NAMESPACE::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	for (int i = 0; i < v3.size(); i++)
		v3[i] = TestStruct(i, i, std::string(std::to_string(i)));
	test_for_type<TestStruct>(v3);


	ofs.close();
}

template <typename T>
void test_for_type(CURRENT_NAMESPACE::vector<T>& vector1)
{
	TEST_INIT();
	typename CURRENT_NAMESPACE::vector<T>::const_reference cref = vector1.front();
	write_result(ofs, cref);
	typename CURRENT_NAMESPACE::vector<T>::reference ref = vector1.front();
	ref = ref * 2;
	write_result(ofs, ref);
	write_result(ofs, vector1.front());
}
