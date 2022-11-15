//
// Created by Cyril Battistolo on 11/15/22.
//

#include "../common.cpp"

std::string testName("max_size");

int main(int argc, char** argv)
{
	{ // max_size vector<float>
		TEST_INIT();
		vector<char> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<float>
		TEST_INIT();
		vector<unsigned char> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<float>
		TEST_INIT();
		vector<int> v;
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<float>
		TEST_INIT();
		vector<long> v(50);
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<float>
		TEST_INIT();
		vector<float> v(5, 42);
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<std::string>
		TEST_INIT();
		vector<std::string> v(50, "heyyyyyy!");
		write_result(ofs, v.max_size());
	}
	{ // max_size vector<TestStruct>
		TEST_INIT();
		vector<TestStruct> v(5, TestStruct(5, -42, "test"));
		write_result(ofs, v.max_size());
	}

	ofs.close();
}
