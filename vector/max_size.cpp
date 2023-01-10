#include "../common/vector_common.cpp"

std::string testName("max_size");

int main(void)
{
    INIT_SIGNAL();
	{ // max_size vector<char>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<char> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<unsigned char>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<unsigned char> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<int>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<int> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<long>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<long> v(50);
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<float>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<float> v(5, 42);
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<std::string>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<std::string> v(50, "heyyyyyy!");
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<TestStruct>
		TEST_INIT();
		CURRENT_NAMESPACE::vector<TestStruct> v(5, TestStruct(5, -42, "test"));
		write_result(ofs, v.max_size());
	}

	ofs.close();
}
