#include "../common.cpp"

std::string testName("push_back");
std::ofstream ofs;

template <typename T>
void test_for_type(const T& value);

int main(int argc, char** argv)
{
	test_for_type<int>(42);
	test_for_type<TestStruct>(TestStruct(1, 1, "1"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Multiple push back
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		for (int i = 0; i < 50; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with existing values in vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(20, value);
		for (int i = 0; i < 30; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with a lot of values
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with a lot of values and existing values in vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10000, value);
		for (int i = 0; i < 10000; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with pre-reserved space
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.reserve(100);
		for (int i = 0; i < 30; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}
	{ // Multiple push back with pre-reserved space but not enough
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.reserve(10);
		for (int i = 0; i < 30; i++)
			v.push_back(value * i);
		write_result(ofs, v);
	}

}
