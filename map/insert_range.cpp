#include "../common/map_common.cpp"
#include <cstdlib>
#include <fstream>
#include <utility>

std::string testName = "insert_range";

int main(void)
{
    INIT_SIGNAL();
	{// Inserting a range of pair<int, int>
		TEST_INIT();

		CURRENT_NAMESPACE::map<int, int> m = generate_map<int, int>(20);
		CURRENT_NAMESPACE::map<int, int> intmap1;
		intmap1.insert(m.begin(), m.end());
		write_result(ofs, intmap1);
	}

	{// Inserting a range of pair<std::string, int>
		TEST_INIT();

		CURRENT_NAMESPACE::map<int, TestStruct> m = generate_map<int, TestStruct>(20);
		CURRENT_NAMESPACE::map<int, TestStruct> m1;
		m1.insert(m.begin(), m.end());
		write_result(ofs, m1);
	}

	{// Inserting a range of pair<TestStruct, int>
		TEST_INIT();

		CURRENT_NAMESPACE::map<TestStruct, TestStruct> m = generate_map<TestStruct, TestStruct>(20);
		CURRENT_NAMESPACE::map<TestStruct, TestStruct> m1;
		m1.insert(m.begin(), m.end());

		write_result(ofs, m1);
	}
	ofs.close();
}
