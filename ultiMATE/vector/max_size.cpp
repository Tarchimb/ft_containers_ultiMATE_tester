//
// Created by Cyril Battistolo on 11/15/22.
//

#include "../common.cpp"

std::string testName("max_size");

int main(int argc, char** argv)
{
	{ // max_size vector<char>
		TEST_INIT();
		ft::vector<char> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<unsigned char>
		TEST_INIT();
		ft::vector<unsigned char> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<int>
		TEST_INIT();
		ft::vector<int> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<long>
		TEST_INIT();
		ft::vector<long> v(50);
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<float>
		TEST_INIT();
		ft::vector<float> v(5, 42);
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<std::string>
		TEST_INIT();
		ft::vector<std::string> v(50, "heyyyyyy!");
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<TestStruct>
		TEST_INIT();
		ft::vector<TestStruct> v(5, TestStruct(5, -42, "test"));
		write_result(ofs, v.max_size());
	}

	ofs.close();
}
