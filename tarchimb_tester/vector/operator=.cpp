#include "vec.hpp"

int main(void)
{
	{
		printTitle("Operator = on empty vector");
		vector	<TYPE> v1;
		vector	<TYPE> v2 = v1;
		vector	<TYPE> v3(v1);
		v2 = v3;
		v3 = v1;
		printVector(v1);
		printVector(v2);
		printVector(v3);
	}
	{
		printTitle("Operator = on vector with 1 element");
		vector	<TYPE> v1(1, VALUE_TYPE);
		vector	<TYPE> v2 = v1;
		vector	<TYPE> v3(v1);
		v2 = v3;
		v3 = v1;
		printVector(v1);
		printVector(v2);
		printVector(v3);
	}
	{
		printTitle("Operator = on vector with multiple elements");
		vector	<TYPE> v1(SIZE, VALUE_TYPE);
		vector	<TYPE> v2 = v1;
		vector	<TYPE> v3(v1);
		v2 = v3;
		v3 = v1;
		printVector(v1);
		printVector(v2);
		printVector(v3);
	}
	{
		printTitle("Operator = on vector with multiple elements and different value");
		vector	<TYPE> v1(SIZE, VALUE_TYPE);
		vector	<TYPE> v2(SIZE, NEW_VALUE);
		vector	<TYPE> v3(v1);
		v2 = v3;
		v3 = v1;
		printVector(v1);
		printVector(v2);
		printVector(v3);
	}
	{
		printTitle("Operator = on vector with std::move function");
		vector	<TYPE> v1(SIZE, VALUE_TYPE);
		vector	<TYPE> v2(SIZE, NEW_VALUE);
		vector	<TYPE> v3(v1);

		v2 = std::move(v1);
		v3 = std::move(v2);
		v1 = std::move(v3);
		printVector(v1);
		printVector(v2);	
		printVector(v3);
	}
}