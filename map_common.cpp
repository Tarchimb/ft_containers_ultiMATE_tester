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
