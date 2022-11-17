#include "../common.cpp"

std::string testName("copy_constructor");

template <typename T>
void test_for_type(const vector<T>& vector1);

template <typename T>
void test_for_capacity(const vector<T> vector1);

int main(int argc, char** argv)
{
	vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(v1);

	vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(v2);

	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(v3);

	v1.clear();
	for(int i = 0; i < 12; i++)
		v1.push_back(i);
	test_for_capacity<int>(v1);

	v2.clear();
	for(double i = 0; i < 10; i++)
		v2.push_back(i);
	test_for_capacity<double>(v2);

	v3.clear();
	for(double i = 0; i < 10; i++)
		v3.push_back(TestStruct(i, i * 10, "nothing"));
	test_for_capacity<TestStruct>(v3);

	ofs.close();
}

template <typename T>
void test_for_type(const vector<T>& vector1)
{
	TEST_INIT();
	vector<T> vector2(vector1);
	write_result<T>(ofs, vector2);
}

template <typename T>
void test_for_capacity(const vector<T> vector1)
{
	TEST_INIT();
	vector<T> vector2(vector1);
	write_result<T>(ofs, vector2);
}
