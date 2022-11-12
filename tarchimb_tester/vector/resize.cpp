#include "vec.hpp"

int	main(void)
{
	vector<TYPE> v(SIZE);
	{
		printTitle("Resize");
		v.resize(0);
		printVector(v);
		v.resize(10000);
		printVector(v);
		v.resize(50);
		printVector(v);
		v.resize(25000);
		printVector(v);
	}
	{
		printTitle("Resize with value");
		v.resize(0, NEW_VALUE);
		printVector(v);
		v.resize(10000, NEW_VALUE);
		printVector(v);
		v.resize(50, NEW_VALUE);
		printVector(v);
		v.resize(25000, NEW_VALUE);
		printVector(v);
	}
}