#include "../common.cpp"

namespace std {
	template <typename U, typename T>
	std::string to_string(const CURRENT_NAMESPACE::pair<U, T>& p) {
		return (std::string(std::to_string(p.first) + " " + std::to_string(p.second)));
//		return std::string();
	}
}

template <typename T>
void write_result(std::ofstream& ofs, const T& val)
{
	ofs << std::to_string(val) << std::endl;
}
