#include "common.cpp"

namespace std {

	template <class U, class T>
	std::string to_string(const CURRENT_NAMESPACE::map<U, T>& m) {
		std::string str;
		//typename CURRENT_NAMESPACE::map<U, T>::const_iterator it;
		typename CURRENT_NAMESPACE::map<U, T>::iterator it;
		for (it = m.begin(); it != m.end(); ++it)
		{
			str += std::to_string(it->first);
			str += ":";
			str += std::to_string(it->second);
			str += "\n";
		}
		return str;
	}
};

template <class U, class T>
void write_result(std::ofstream& ofs, const CURRENT_NAMESPACE::map<U, T>& map, const bool printContent=true) {
	//ofs << "size: " + std::to_string(map.size()) << std::endl;
	ofs << "empty: " + std::to_string(map.empty()) << std::endl;
	//if (printContent)
	//	ofs << std::to_string(map);
}
