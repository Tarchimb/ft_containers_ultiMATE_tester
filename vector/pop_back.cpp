#include "../common/vector_common.cpp"

std::string testName("pop_back");

template <typename T>
void test_for_type(const T& value);

int main(void)
{
    INIT_SIGNAL();
	test_for_type<int>(1);
	test_for_type<TestStruct>(TestStruct(1, 1, "1"));

	ofs.close();
}

template <typename T>
void test_for_type(const T& value)
{
	{ // Pop back with filled vector
		TEST_INIT();

		CURRENT_NAMESPACE::vector<T> vector(20, value);
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
		TEST_INIT();

		CURRENT_NAMESPACE::vector<T> vector;
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
		TEST_INIT();

		CURRENT_NAMESPACE::vector<T> vector;
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
