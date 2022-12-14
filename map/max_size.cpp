#include "../map_common.cpp"

std::string testName("max_size");

int main(int argc, char **argv) {
	{ // max_size map<char, char>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<char, char> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}
	{ // max_size map<unsigned char, unsigned char>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<unsigned char, unsigned char> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}
	{ // max_size map<int, int>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<int, int> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}
	{ // max_size map<long, long>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<long, long> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}
	{ // max_size map<float, float>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<float, float> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}
	{ // max_size map<std::string, std::string>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<std::string, std::string> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}
	{ // max_size map<TestStruct, TestStruct>
		TEST_INIT() {
			CURRENT_NAMESPACE::map<TestStruct, TestStruct> m;
			write_result(ofs, m.max_size());
			exit(0);
		}
	}

	ofs.close();
}
