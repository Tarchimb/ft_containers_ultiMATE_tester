#include "../common.cpp"

std::string testName("operator_brackets");
std::ofstream ofs;

template <typename T>
void test(std::ofstream& ofs, vector<T>& vector1);

int main(int argc, char** argv)
{
	open_file(ofs, "operator_brackets");

	vector<int> v1(10, 42);
	v1[3] = 420;
	test<int>(ofs, v1);

	vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test<double>(ofs, v2);

	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[500] = TestStruct(-5, 213, "nothing");
	test<TestStruct>(ofs, v3);

	ofs.close();
}

template <typename T>
void test(std::ofstream& ofs, vector<T>& vector1)
{
	typename vector<T>::const_reverse_iterator it = vector1.rend();
	write_result<T>(ofs, *--it);
	typename vector<T>::reverse_iterator it2 = vector1.rend();
	write_result<T>(ofs, (*--it2));
	write_result<bool>(ofs, &(*it2) == &(*it));
}

