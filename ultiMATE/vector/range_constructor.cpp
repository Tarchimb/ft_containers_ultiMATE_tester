#include "../common.cpp"

std::string testName("range_constructor");
std::ofstream ofs;

template <typename T>
void test_for_type(const T& value);

int main(int argc, char** argv)
{
	test_for_type<int>(42);
	test_for_type<float>(42.4242);
	test_for_type<TestStruct>(TestStruct(10, 5, "test"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Classic range constructor
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		try {
			vector<T> vector1(100, value);
			vector<T> vector2(vector1.begin(), vector1.end());
			write_result(ofs, vector2);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
	{ // Range constructor with modified iterators
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		try {
			vector<T> vector1(100, value);
			vector<T> vector2(vector1.begin() + 25, vector1.end() - 25);
			write_result(ofs, vector2);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
	{ // Range constructor with begin = end
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		try {
			vector<T> vector1(100, value);
			vector<T> vector2(vector1.begin() + 50, vector1.begin() - 50);
			write_result(ofs, vector2);
		}
		catch (std::exception& e)
		{
			write_result(ofs, e.what());
		}
	}
}

