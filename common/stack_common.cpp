#include "../common.cpp"

namespace std {
	template <typename T, typename C>
	std::string to_string(CURRENT_NAMESPACE::stack<T, C> stack) {
		std::string str;
		while (stack.empty() == false)
		{
			str += std::to_string(stack.pop());
			stack.pop();
		}
		return str;
	}
}

template <typename T, typename C>
void write_result(std::ofstream& ofs, CURRENT_NAMESPACE::stack<T, C> stack, const bool printContent=true) {
	ofs << "size: " + std::to_string(stack.size()) << std::endl;
	ofs << "empty: " + std::to_string(stack.empty()) << std::endl;
	if (printContent)
		while (stack.empty() == false)
		{
			ofs << std::to_string(stack.top()) << std::endl;
			stack.pop();
		}
}

template <typename T>
void write_result(std::ofstream& ofs, const T& val)
{
	ofs << std::to_string(val) << std::endl;
}
