#include "../map_common.cpp"
#include <cstdlib>
#include <utility>

std::string testName = "insert_range";

int main(void)
{
	{// Inserting a range of pair<int, int>
		TEST_INIT();
		INIT_MAPS

		CURRENT_NAMESPACE::map<int, int> intmap1;
		intmap1.insert(intmap.begin(), intmap.end());
		write_result(ofs, intmap1);
	}

	{// Inserting a range of pair<std::string, int>
		TEST_INIT();
		INIT_MAPS

		CURRENT_NAMESPACE::map<std::string, std::string> strmap1;
		strmap1.insert(strmap.begin(), strmap.end());
		write_result(ofs, strmap1);
	}

	{// Inserting a range of pair<TestStruct, int>
		TEST_INIT();
		INIT_MAPS

		CURRENT_NAMESPACE::map<TestStruct, TestStruct> TestStructmap1;
		TestStructmap1.insert(TestStructmap.begin(), TestStructmap.end());

		write_result(ofs, TestStructmap1);
	}
	ofs.close();
}
