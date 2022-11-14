#include "../common.cpp"

std::string testName("swap");

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value);

int main(int argc, char** argv)
{
	test_for_type<int>(ofs, 10);
	test_for_type<TestStruct>(ofs, TestStruct(5, -42, "bergamote"));
}

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value)
{
	typedef typename vector<T>::iterator iterator;

	{
		TEST_INIT();
		vector<T> v1(5, value);
		vector<T> v2(5, value * 2);
		iterator it1 = v1.begin();
		iterator it2 = v2.begin();
		T& ref1 = v1.front();
		T& ref2 = v2.front();

		v1.swap(v2);
		write_result(ofs, v1);
		write_result(ofs, *it1);
		write_result(ofs, ref1);
		write_result(ofs, v2);
		write_result(ofs, *it2);
		write_result(ofs, ref2);
		write_result(ofs, it1 == v1.begin());
		write_result(ofs, it1 == v2.begin());
	}
	{
		TEST_INIT();
		vector<T> v1(2, value);
		vector<T> v2(5, value * 2);
		iterator it1 = v1.begin() + 1;
		iterator it2 = v2.begin() + 1;
		T& ref1 = v1.front();
		T& ref2 = v2.front();

		v1.swap(v2);
		write_result(ofs, v1);
		write_result(ofs, *it1);
		write_result(ofs, ref1);
		write_result(ofs, v2);
		write_result(ofs, *it2);
		write_result(ofs, ref2);
		write_result(ofs, it1 == v1.begin() + 1);
		write_result(ofs, it1 == v2.begin() + 1);
	}
	{
		TEST_INIT();
		vector<T> v1(200, value);
		vector<T> v2(1000, value * 2);
		iterator it1 = v1.begin() + 1;
		iterator it2 = v2.begin() + 1;
		T& ref1 = v1.front();
		T& ref2 = v2.front();

		v1.swap(v2);
		write_result(ofs, v1);
		write_result(ofs, *it1);
		write_result(ofs, ref1);
		write_result(ofs, v2);
		write_result(ofs, *it2);
		write_result(ofs, ref2);
		write_result(ofs, it1 == v1.begin() + 1);
		write_result(ofs, it1 == v2.begin() + 1);
	}
}
