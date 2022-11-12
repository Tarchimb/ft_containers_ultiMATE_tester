#include "vec.hpp"

int	main(void)
{
	vector	<TYPE> v1(SIZE, VALUE_TYPE);
	vector	<TYPE> v2(SIZE * 4, NEW_VALUE);
	iter it;
	iter ite;
	{
		printTitle("Assign with two iterators");
		vector	<TYPE> v3(SIZE, NEW_VALUE);
		assignIterator(v3, it, ite);
		v3.assign(v1.begin(), v1.end());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v2.begin(), v2.begin());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v1.begin() + SIZE / 2, v1.end());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v2.begin() + SIZE / 2, v2.end());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v1.begin(), v1.end() - SIZE / 2);
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v2.begin(), v2.end() - SIZE / 2);
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v1.begin() + SIZE / 2, v1.end() - SIZE / 2);
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v2.begin() + SIZE / 2, v2.end() - SIZE / 2);
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v1.begin(), v1.begin());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v2.begin(), v2.begin());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v1.end(), v1.end());
		iteratorValidity(v3, it, ite);
		printVector(v3);

		assignIterator(v3, it, ite);
		v3.assign(v2.end(), v2.end());
		iteratorValidity(v3, it, ite);
		printVector(v3);
	}
}