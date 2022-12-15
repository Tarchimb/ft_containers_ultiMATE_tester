#include "../common/map_common.cpp"
#include <cstdlib>
#include <utility>

std::string testName = "insert_range";

int arr_int[50] = {71, 87, 70, 22, 28, 2, 43, 99, 32, 46, 76, 69, 51, 36, 19, 42, 86, 10, 62, 20, 49, 29, 64, 56, 67, 15, 38, 12, 57, 55, 60, 26, 96, 83, 25, 47, 3, 100, 11, 5, 66, 91, 23, 63, 24, 85, 4, 53, 34, 28};
int arr_int_size = 50;

std::string arr_str[50] = {"yyXpSq5z", "4185gMz9", "jBSHLhkL","Ec6tad3M","4N2d0jFK","bawse5Bn","yPV3JY31","TM4etSrh","Jupj4s5l","R4orvvFJ","hpHjD1DN","JgqO9gBL","MJLk2cXf","gGmgZnif","iHdq1BnG","GdJNCISF","urAeeV8b","y77BzwHS","vwwZGHpN","ZK1F49cD","2xgh2sBj","kDiSzW8g","bJupzHeD","E2dvoHAS","g4v3d6vQ","zn3Culxt","BOolfjV6","zZmbkp4I","yfQeRmvt","dkxW6Cyd","QttC2iJN","O34E2cfY","PMDQwCPL","RDasl08N","JRsH76WC","ql8q7QGf","2hykOiLJ","GtL80u79","qVAQmYoR","rFsQ7Z9i","kXTpgSmj","dMpQ4jrC","ibSNzJ2A","PZoUpMNl","8qYabOgZ","d71Oa0oy","SL9RxxIk","GooMVhob","yTNqUQln","mJEe02di"};
int arr_str_size = 50;

int main(void)
{
	{// Inserting a range of pair<int, int>
		TEST_INIT();
		srand(0);


		CURRENT_NAMESPACE::map<int, int> intmap;
		for (int i = 0; i < arr_int_size; i++)
			intmap.insert(CURRENT_NAMESPACE::make_pair(arr_int[i], 0));

		CURRENT_NAMESPACE::map<int, int> intmap1;
		intmap1.insert(intmap.begin(), intmap.end());
		write_result(ofs, intmap1);
	}

	{// Inserting a range of pair<std::string, int>
		TEST_INIT();
		srand(0);

		CURRENT_NAMESPACE::map<std::string, int> strmap;
		for (int i = 0; i < arr_int_size; i++)
			strmap.insert(CURRENT_NAMESPACE::make_pair(arr_str[i], 0));

		CURRENT_NAMESPACE::map<std::string, int> strmap1;
		strmap1.insert(strmap.begin(), strmap.end());
		write_result(ofs, strmap1);
	}

	{// Inserting a range of pair<TestStruct, int>
		TEST_INIT();
		srand(0);

		CURRENT_NAMESPACE::map<TestStruct, int> test_structmap;
		for (int i = 0; i < arr_int_size; i++)
		{
			test_structmap.insert(CURRENT_NAMESPACE::make_pair(TestStruct(rand() % 100, rand() % 100, "a"), 0));
		}
		CURRENT_NAMESPACE::map<TestStruct, int> test_structmap1;
		test_structmap1.insert(test_structmap.begin(), test_structmap.end());

		write_result(ofs, test_structmap1);
	}
	ofs.close();
}
