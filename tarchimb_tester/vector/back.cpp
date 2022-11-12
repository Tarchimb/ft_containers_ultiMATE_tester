#include "vec.hpp"

int	main(void)
{
	vector<TYPE>				v(SIZE, VALUE_TYPE);
	printTitle("Back");
	{
		refer	it = v.back();
		const_refer	it1 = v.back();
		printVector(v);
	}
}