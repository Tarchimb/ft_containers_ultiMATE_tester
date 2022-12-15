#include "../common/map_common.cpp"
#include <cstdlib>
#include <fstream>
#include <utility>

std::string testName = "insert_range";

int main(void)
{
	{// Inserting a range of pair<int, int>
		TEST_INIT(){
			srand(0);

			CURRENT_NAMESPACE::map<int, int> intmap;
			for (int i = 0; i < arr_int_size; i++)
				intmap.insert(CURRENT_NAMESPACE::make_pair(arr_int[i], 0));

			CURRENT_NAMESPACE::map<int, int> intmap1;
			intmap1.insert(intmap.begin(), intmap.end());
			write_result(ofs, intmap1);
			exit(0);
		}
	}

	{// Inserting a range of pair<std::string, int>
		TEST_INIT(){
			srand(0);

			CURRENT_NAMESPACE::map<std::string, int> strmap;
			for (int i = 0; i < arr_int_size; i++)
				strmap.insert(CURRENT_NAMESPACE::make_pair(arr_str[i], 0));

			CURRENT_NAMESPACE::map<std::string, int> strmap1;
			strmap1.insert(strmap.begin(), strmap.end());
			write_result(ofs, strmap1);
			exit(0);
		}
	}

	{// Inserting a range of pair<TestStruct, int>
		TEST_INIT(){
			srand(0);

			CURRENT_NAMESPACE::map<TestStruct, int> test_structmap;
			for (int i = 0; i < arr_int_size; i++)
			{
				test_structmap.insert(CURRENT_NAMESPACE::make_pair(TestStruct(rand() % 100, rand() % 100, "a"), 0));
			}
			CURRENT_NAMESPACE::map<TestStruct, int> test_structmap1;
			test_structmap1.insert(test_structmap.begin(), test_structmap.end());

			write_result(ofs, test_structmap1);
			exit(0);
		}
	}
	ofs.close();
}
