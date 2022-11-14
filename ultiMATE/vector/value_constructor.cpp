#include "../common.cpp"

std::string testName("value_constructor");
std::ofstream ofs;

template <typename T>
void test_for_type(std::ofstream& ofs, const int& count, const T value);

int main(int argc, char** argv)
{
	test_for_type<int>(ofs, 5, 42);
	test_for_type<TestStruct>(ofs, 5, TestStruct());

	ofs.close();
}

template <typename T>
void test_for_type(std::ofstream& ofs, const int& count, const T value)
{
	{ // classic count and value
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		try {
			vector<T> vector(count, value);
			write_result(ofs, vector);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
	{ // count = 0
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		try {
			vector<T> vector(0, value);
			write_result(ofs, vector);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
}
