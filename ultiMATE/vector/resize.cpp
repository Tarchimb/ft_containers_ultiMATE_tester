#include "../common.cpp"

std::string testName("resize");
std::ofstream ofs;

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value);

int main(int argc, char** argv)
{
	test_for_type<int>(ofs, 10);
	test_for_type<float>(ofs, 10.5f);
	test_for_type<TestStruct>(ofs, TestStruct(5, -42, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, const T& value)
{
	{ // resize normal value with empty vector
		change_ofs_to_next_test(ofs, testName);
		vector<T> v;
		v.clear();
		v.resize(5, value);
		write_result(ofs, v);
	}
	{ // resize less than currently reserved
		change_ofs_to_next_test(ofs, testName);
		vector<T> v(50);
		v.resize(5, value);
		write_result(ofs, v);
	}
	{ // resize 0
		change_ofs_to_next_test(ofs, testName);
		vector<T> v(5, value);
		v.resize(0, value);
		write_result(ofs, v);
	}
	{ // multiple resize
		change_ofs_to_next_test(ofs, testName);
		vector<T> v(5, value);
		v.resize(5, value);
		v.resize(5, T());
		v.resize(9, value);
		v.resize(9, T());
		v.resize(2, value);
		v.resize(2, T());
		write_result(ofs, v);
	}
	{ // resize more than currently reserved
		change_ofs_to_next_test(ofs, testName);
		vector<T> v(5, value);
		v.resize(100, value);
		write_result(ofs, v);
	}
	{ // resize more than currently reserved with large size
		change_ofs_to_next_test(ofs, testName);
		vector<T> v(5, value);
		v.resize(10000, value);
		write_result(ofs, v);
	}
}

