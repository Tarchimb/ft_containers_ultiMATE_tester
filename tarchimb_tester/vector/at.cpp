#include "vec.hpp"

int main(void)
{
	vector<TYPE> v(SIZE, VALUE_TYPE);
	printTitle("At");
	{
		printVector(v);
		for (size_t i = 0; i < v.size(); i++)
			v.at(i) = NEW_VALUE;
		printVector(v);
	}
	{
		try
		{
			v.at(v.size());
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
}