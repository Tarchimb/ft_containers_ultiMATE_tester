#include "../common.cpp"

namespace std {
	template <typename T>
	std::string to_string(const CURRENT_NAMESPACE::vector<T>& v) {
		std::string str;
		for (int i = 0; i < v.size(); i++)
			str += std::to_string(v[i]);
		return str;
	}
}

template <typename T>
void write_result(std::ofstream& ofs, const CURRENT_NAMESPACE::vector<T>& vector, const bool printContent=true) {
	ofs << "size: " + std::to_string(vector.size()) << std::endl;
	ofs << "capacity: " + std::to_string(vector.capacity()) << std::endl;
	ofs << "empty: " + std::to_string(vector.empty()) << std::endl;
	if (printContent)
		for (int i = 0; i < vector.size(); i++)
			ofs << std::to_string(vector[i]) << std::endl;
}

template <typename T>
void write_result(std::ofstream& ofs, const T& val)
{
	ofs << std::to_string(val) << std::endl;
}
