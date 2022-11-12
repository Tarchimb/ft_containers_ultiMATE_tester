#include "vec.hpp"

int	main()
{
	{
		printTitle("Default constructor");
		vector<TYPE>				v;

		printVector(v);
	}
	{
		printTitle("Fill constructor");
		vector<TYPE>				v(SIZE);

		printVector(v);
	}
	{
		printTitle("Fill constructor with value");
		vector<TYPE>				v(SIZE, VALUE_TYPE);
		vector<TYPE>				v1(0, VALUE_TYPE);

		printVector(v);
		printVector(v1);
	}
	{
		printTitle("Copy constructor");
		vector<TYPE>				v(SIZE, VALUE_TYPE);
		vector<TYPE>				v2(v);
		vector<TYPE>				v3(v2);

		printVector(v);
		printVector(v2);
		printVector(v3);
	}
	{
		printTitle("Range constructor");
		vector<TYPE>				base(SIZE, VALUE_TYPE);
		vector<TYPE>				v(base.begin(), base.end());
		vector<TYPE>				v2(base.begin() + SIZE, base.end());

		printVector(v);
		printVector(v2);
	}
	return (0);
}