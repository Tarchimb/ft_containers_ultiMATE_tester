#include "../common.cpp"

std::string testName("data");

template <typename T>
void test_for_type(ft::vector<T>& vector1);

int main(int argc, char** argv)
{
	ft::vector<int> v1(10, 0);
	for (int i = 0; i < v1.size(); i++)
		v1[i] = i + 1;
	test_for_type<int>(v1);

	ft::vector<double> v2(1000, 42.424242f);
	for (int i = 0; i < v2.size(); i++)
		v2[i] = i + 1;
	test_for_type<double>(v2);

	ft::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	for (int i = 0; i < v3.size(); i++)
		v3[i] = TestStruct(i + 1, i + 1, std::string(std::to_string(i + 1)));
	test_for_type<TestStruct>(v3);

	ofs.close();
}

template <typename T>
void test_for_type(ft::vector<T>& vector1)
{
	TEST_INIT();
	const typename ft::vector<T>::value_type* cval = vector1.data();
	write_result(ofs, *cval);
	typename ft::vector<T>::value_type* val = vector1.data();
	*val = *val * 2;
	write_result(ofs, *val);
	write_result(ofs, *(vector1.data()));
	write_result(ofs, &(*val) == &(*cval));
	write_result(ofs, &(*val) == &(*vector1.begin()));
}
