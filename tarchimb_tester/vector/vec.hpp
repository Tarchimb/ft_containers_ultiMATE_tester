#ifndef VEC_HPP
# define VEC_HPP

#include "../../containers/vector.hpp"
#include <vector>
#include <iostream>
#include <string>

#define SIZE 256

#ifndef NEW_VALUE
#define NEW_VALUE 420
#endif

#ifndef FT
#define FT 1
#endif

#ifndef TYPE
#define TYPE int
#endif

#ifndef VALUE_TYPE
#define VALUE_TYPE 42
#endif

#if FT == 1
	using namespace ft;
#else
	using namespace std;
#endif

typedef vector<TYPE>::iterator				iter;
typedef vector<TYPE>::const_iterator		const_iter;
typedef vector<TYPE>::reference				refer;
typedef vector<TYPE>::const_reference		const_refer;
typedef vector<TYPE>::pointer				point;

// #define PRINT(x) std::cout << #x << std::endl;

void	printTitle(std::string title)
{
	std::cout << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "====================" << std::endl;
}

template <typename T>
void	printVector(vector<T> &v)
{
	typename vector<T>::iterator it = v.begin();
	typename vector<T>::iterator ite = v.end();
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	if (v.empty())
		return ;
	std::cout << "begin: " << *v.begin() << std::endl;
	std::cout << "content: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	assignIterator(vector<TYPE> &v, iter it, iter ite)
{
	it = v.begin();
	ite = v.end();
}

template <typename T>
void	iteratorValidity(vector <TYPE> &v, T begin, T end)
{
	T it = v.begin();
	T ite = v.end();

	std::cout << "BEGIN ISN'T SAME!" << std::endl;
	std::cout << (it == begin) << std::endl;
	std::cout << "END ISN'T SAME!" << std::endl;
	std::cout << (ite == end) << std::endl;
}

#endif