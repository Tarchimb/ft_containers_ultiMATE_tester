#include "vec.hpp"

int main(void)
{
	vector<TYPE> v(SIZE, VALUE_TYPE);
	printTitle("Operator[]");
	{
		printVector(v);
		for (size_t i = 0; i < v.size(); i++)
			v[i] = NEW_VALUE;
		printVector(v);
	}
}