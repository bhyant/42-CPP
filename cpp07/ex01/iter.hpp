#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename F>
void print(const F &val)
{
	std::cout << "Value: " << val << std::endl;
}

template <typename T, typename F>
void iter(T *array, const std::size_t len, F function)
{
	if (!array)
		return ;
	for (std::size_t i = 0; i < len; i++)
		function(array[i]);
}

#endif
