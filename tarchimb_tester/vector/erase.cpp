#include "vec.hpp"

int main(void)
{
	vector<TYPE> v(SIZE, VALUE_TYPE);
	{
		printTitle("Erase");
		iter it = v.erase(v.begin());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 1);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 10);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 10, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 50);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 50, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 25);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 25, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 12);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 12, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 6);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 6, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 3);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 3, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 1);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 1, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.begin(), v.begin() + 0);
		std::cout << "Value of it: " << *it << std::endl;
		it = v.erase(v.end() - 0, v.end());
		std::cout << "Value of it: " << *it << std::endl;
		printVector(v);
	}
}