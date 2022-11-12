#include "vec.hpp"

int	main(void)
{
	vector	<TYPE> v1(SIZE, VALUE_TYPE);
	iter it;
	iter ite;
	{
		printTitle("Assign with SIZE copies of value");
		vector	<TYPE> v3;
		assignIterator(v3, it, ite);
		v3.assign(SIZE, NEW_VALUE);
		iteratorValidity(v3, it, ite);
		printVector(v3);

		// assignIterator(v3, it, ite);
		// v3.assign(SIZE * 0, NEW_VALUE);
		// iteratorValidity(v3, it, ite);
		// printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(SIZE * 0 + 1, VALUE_TYPE);
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(SIZE * 4, NEW_VALUE);
		iteratorValidity(v3, it, ite);
		printVector(v3);
		
	}
}