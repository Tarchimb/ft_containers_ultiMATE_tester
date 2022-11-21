#include "../../common.cpp"
#include <vector>

void time_diff(struct timeval start, std::string out)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	int time_taken = ((end.tv_sec - start.tv_sec) * 1000
		+ 1e-3 * (end.tv_usec - start.tv_usec));
	std::cout << out << time_taken << " ms " << endl;
}

template <class T>
void tests_huge_sizes(long nb, const T& value);

template <class T>
void tests_small_sizes(long nb, const T&value);

int main(void){
	

	std::cout << "Starting tests" << std::endl;
	
	tests_huge_sizes<int>(300000000, 10);
	tests_huge_sizes<TestStruct>(300000000, TestStruct(10, 10, "HELLO"));

	tests_small_sizes<int>(500000, 10);
	tests_small_sizes<TestStruct>(500000, TestStruct(10, 10, "HELLO"));

	std::cout << "Destructor is being called" << std::endl;
	return 0;
}

template <class T>
void tests_huge_sizes(long nb, const T& value)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	std::vector<T> v(nb, value);
	time_diff(start, "std test: ");

	gettimeofday(&start, NULL);
	ft::vector<T> v1(nb, value);
	time_diff(start, "ft test: ");
}

template <class T>
void tests_small_sizes(long nb, const T&value)
{

	struct timeval	start;
	gettimeofday(&start, NULL);
	std::vector<T> v2(nb, value);
	std::vector<T> v3(nb, value);
	std::vector<T> v4(nb, value);
	std::vector<T> v5(nb, value);
	std::vector<T> v6(nb, value);
	std::vector<T> v7(nb, value);
	std::vector<T> v8(nb, value);
	std::vector<T> v9(nb, value);
	std::vector<T> v10(nb, value);
	std::vector<T> v11(nb, value);
	std::vector<T> v12(nb, value);
	time_diff(start, "std test: ");

	gettimeofday(&start, NULL);
	ft::vector<T> v22(nb, value);
	ft::vector<T> v33(nb, value);
	ft::vector<T> v44(nb, value);
	ft::vector<T> v55(nb, value);
	ft::vector<T> v66(nb, value);
	ft::vector<T> v77(nb, value);
	ft::vector<T> v88(nb, value);
	ft::vector<T> v99(nb, value);
	ft::vector<T> v100(nb, value);
	ft::vector<T> v111(nb, value);
	ft::vector<T> v122(nb, value);
	time_diff(start, "ft test: ");
}
