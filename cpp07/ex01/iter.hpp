#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void print(T &val)
{
	std::cout << "Value: " << val << std::endl;
}

template <typename T>
void iter(T *array, const std::size_t len, void (*f)(T&))
{
	if (!array)
		return ;
	for (std::size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif
