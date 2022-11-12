#include "vec.hpp"

int	main(void)
{
	vector<TYPE>				v(SIZE, VALUE_TYPE);
	printTitle("Front");
	{
		refer	it = v.front();
		std::cout << "v.front(): " << it << std::endl;
		printVector(v);
	}
	{
		const_refer	it = v.front();
		std::cout << "v.front(): " << it << std::endl;
	}
}