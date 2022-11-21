#include "../common.cpp"

std::string testName("rbegin");

template <typename T>
void test_for_type(std::ofstream& ofs, ft::vector<T>& vector1);

int main(int argc, char** argv)
{
	ft::vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(ofs, v1);

	ft::vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(ofs, v2);

	ft::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(ofs, v3);

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, ft::vector<T>& vector1)
{
	TEST_INIT();

	typename ft::vector<T>::const_reverse_iterator it = vector1.rbegin();
	write_result<T>(ofs, *it);
	typename ft::vector<T>::reverse_iterator it2 = vector1.rbegin();
	write_result<T>(ofs, (*it2));
	write_result<bool>(ofs, &(*it2) == &(*it));
}
