#include "../common.cpp"
#include "./other_common.cpp"
#include <utility>

const int ARR_INT[50] = {71, 87, 70, 22, 28, 2, 43, 99, 32, 46, 76, 69, 51, 36, 19, 42, 86, 10, 62, 20, 49, 29, 64, 56, 67, 15, 38, 12, 57, 55, 60, 26, 96, 83, 25, 47, 3, 100, 11, 5, 66, 91, 23, 63, 24, 85, 4, 53, 34, 28};\

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

template<class T, class U>
CURRENT_NAMESPACE::pair<T, U> generate_pair(int index, bool is_linear)
{
	T key = T();
	U value = U();
	
	for (int i = 0; i < (is_linear ? index : ARR_INT[index]); i++) {
		++key;
		++value;
	} 
	return CURRENT_NAMESPACE::make_pair(key, value);
}

template<class T, class U, class C = std::less<T> >
CURRENT_NAMESPACE::map<T, U, C> generate_map(unsigned int size, bool is_linear = false)
{
	CURRENT_NAMESPACE::map<T, U, C> m;

	if (size > 50)
		size = 50;
	for (unsigned int i = 0; i < size; i++)
	{
		m.insert(generate_pair<T, U>(i, is_linear));
	}
	return m;
}
