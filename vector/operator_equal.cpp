#include "../common/vector_common.cpp"
#include <fstream>

std::string testName("operator_equal");

template <typename T>
void test_for_type(const CURRENT_NAMESPACE::vector<T>& vector1, const T& value);

int main(void)
{
    INIT_SIGNAL();
	CURRENT_NAMESPACE::vector<int> v1(10, 42);
	v1[3] = 420;
	test_for_type<int>(v1, 42);

	CURRENT_NAMESPACE::vector<double> v2(1000, 42.424242f);
	v2[500] = 0.0f;
	test_for_type<double>(v2, 42.0f);

	CURRENT_NAMESPACE::vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	v3[50] = TestStruct(-5, 213, "nothing");
	test_for_type<TestStruct>(v3, TestStruct(1, 2, "3"));


	ofs.close();
}

template <typename T>
void test_for_type(const CURRENT_NAMESPACE::vector<T>& vector1, const T& value)
{
	{ // Replace empty vector with another empty vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector;
		CURRENT_NAMESPACE::vector<T> vector2;
		vector = vector2;
		write_result<T>(ofs, vector);
	}
	{ // Replace empty vector with filled vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector2;
		vector2 = vector1;
		write_result<T>(ofs, vector2);
	}
	{ // Replace filled vector witht another filled vector
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector(5, T());
		CURRENT_NAMESPACE::vector<T> vector2(5, value);
		vector = vector2;
		write_result<T>(ofs, vector);
	}
	{ // Replace filled vector witht another filled vector (dst being larger than src)
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector(15, T());
		CURRENT_NAMESPACE::vector<T> vector2(5, value);
		vector = vector2;
		write_result<T>(ofs, vector);
	}
	{ // Replace filled vector witht another filled vector (dst being smaller than src)
		TEST_INIT();
		CURRENT_NAMESPACE::vector<T> vector(5, T());
		CURRENT_NAMESPACE::vector<T> vector2(15, value);
		vector = vector2;
		write_result<T>(ofs, vector);
	}
}
