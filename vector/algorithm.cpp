#include "../common/vector_common.cpp"
#include <algorithm>
#include <random>

std::string testName("algorithm");

template <typename T>
void test_std_algorithm(CURRENT_NAMESPACE::vector<T> array);

template <typename T>
static T op_increase(T i) {return ++i;}

int main(void)
{
    INIT_SIGNAL();

	CURRENT_NAMESPACE::vector<int>	v_int;
	for (int i = 0; i < 10; i++)
		v_int.push_back(i);
	test_std_algorithm<int>(v_int);

	CURRENT_NAMESPACE::vector<TestStruct>	v_struct;
	for (int i = 0; i < 10; i++)
		v_struct.push_back(TestStruct(i, i, std::to_string(i)));
	test_std_algorithm<TestStruct>(v_struct);

	ofs.close();
}


template <typename T>
void test_std_algorithm(CURRENT_NAMESPACE::vector<T> array)
{
	{
		TEST_INIT();
		std::transform(array.begin(), array.end(), array.begin(), op_increase<T>);
		write_result(ofs, array);
	}
	{
		TEST_INIT();
		std::reverse(array.begin(), array.end());
		write_result(ofs, array);
	}
	{
		TEST_INIT();
		std::sort(array.begin(), array.end());
		write_result(ofs, array);
	}
}
