#include "common.cpp"

template <class T>
struct ft_greater {
    bool operator()(const T lhs, const T rhs) const
    {
        return rhs < lhs;
    }
};

namespace std {

	template <class T, class U, class C = std::less<T> >
	std::string to_string(const CURRENT_NAMESPACE::map<T, U, C>& m) {
		std::string str;
		typename CURRENT_NAMESPACE::map<T, U>::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it)
		{
			str += std::to_string(it->first);
			str += ":";
			str += std::to_string(it->second);
			str += "\n";
		}
		return str;
	}
}

template <class T, class U, class C = std::less<T> >
void write_result(std::ofstream& ofs, const CURRENT_NAMESPACE::map<T, U, C>& map, const bool printContent=true) {
	ofs << "size: " + std::to_string(map.size()) << std::endl;
	ofs << "empty: " + std::to_string(map.empty()) << std::endl;
	if (printContent)
		ofs << std::to_string(map);
}

#define INIT_MAPS\
	const int ARR_SIZE = 50;\
	int arr_int[ARR_SIZE] = {71, 87, 70, 22, 28, 2, 43, 99, 32, 46, 76, 69, 51, 36, 19, 42, 86, 10, 62, 20, 49, 29, 64, 56, 67, 15, 38, 12, 57, 55, 60, 26, 96, 83, 25, 47, 3, 100, 11, 5, 66, 91, 23, 63, 24, 85, 4, 53, 34, 28};\
	std::string arr_str[ARR_SIZE] = {"yyXpSq5z", "4185gMz9", "jBSHLhkL","Ec6tad3M","4N2d0jFK","bawse5Bn","yPV3JY31","TM4etSrh","Jupj4s5l","R4orvvFJ","hpHjD1DN","JgqO9gBL","MJLk2cXf","gGmgZnif","iHdq1BnG","GdJNCISF","urAeeV8b","y77BzwHS","vwwZGHpN","ZK1F49cD","2xgh2sBj","kDiSzW8g","bJupzHeD","E2dvoHAS","g4v3d6vQ","zn3Culxt","BOolfjV6","zZmbkp4I","yfQeRmvt","dkxW6Cyd","QttC2iJN","O34E2cfY","PMDQwCPL","RDasl08N","JRsH76WC","ql8q7QGf","2hykOiLJ","GtL80u79","qVAQmYoR","rFsQ7Z9i","kXTpgSmj","dMpQ4jrC","ibSNzJ2A","PZoUpMNl","8qYabOgZ","d71Oa0oy","SL9RxxIk","GooMVhob","yTNqUQln","mJEe02di"};\
\
	CURRENT_NAMESPACE::map<int, int> intmap;\
	for (int i = 0; i < ARR_SIZE; i++)\
		intmap.insert(CURRENT_NAMESPACE::make_pair(arr_int[i], arr_int[i]));\
\
	CURRENT_NAMESPACE::map<std::string, std::string> strmap;\
	for (int i = 0; i < ARR_SIZE; i++)\
		strmap.insert(CURRENT_NAMESPACE::make_pair(arr_str[i], arr_str[i]));\
\
	CURRENT_NAMESPACE::map<int, TestStruct> int_TestStructmap;\
	for (int i = 0; i < ARR_SIZE; i++)\
		int_TestStructmap.insert(CURRENT_NAMESPACE::make_pair(arr_int[i], TestStruct(arr_int[i], 0, "a")));\
\
	CURRENT_NAMESPACE::map<TestStruct, int> TestStruct_intmap;\
	for (int i = 0; i < ARR_SIZE; i++)\
		TestStruct_intmap.insert(CURRENT_NAMESPACE::make_pair(TestStruct(arr_int[i], 0, "a"), arr_int[i]));\
\
	CURRENT_NAMESPACE::map<TestStruct, TestStruct> TestStructmap;\
	for (int i = 0; i < ARR_SIZE; i++)\
		TestStructmap.insert(CURRENT_NAMESPACE::make_pair(TestStruct(arr_int[i], 0, "a"), TestStruct(arr_int[i], 0, "a")));
