#include "../common.cpp"

std::string testName("pop_back");
std::ofstream ofs;

template <typename T>
void test_for_type(const T& value);

int main(int argc, char** argv)
{
	test_for_type<int>(1);
	test_for_type<TestStruct>(TestStruct(1, 1, "1"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Pop back with filled vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;

		vector<T> vector(20, value);
		const int SIZE = vector.size();
		for (int i = 0; i < SIZE; i++)
		{
			if (i == SIZE / 2)
				write_result(ofs, vector); // half way check
			vector.pop_back();
		}
		write_result(ofs, vector);
	}
	{ // Pop back with empty vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;

		vector<T> vector;
		vector.clear();
		const int SIZE = vector.size();
		for (int i = 0; i < SIZE; i++)
		{
			if (i == SIZE / 2)
				write_result(ofs, vector); // half way check
			vector.pop_back();
		}
		write_result(ofs, vector);
	}
	{ // Pop back with reserved space
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;

		vector<T> vector;
		vector.reserve(100);
		const int SIZE = vector.size();
		for (int i = 0; i < SIZE; i++)
		{
			if (i == SIZE / 2)
				write_result(ofs, vector); // half way check
			vector.pop_back();
		}
		write_result(ofs, vector);
	}

}
