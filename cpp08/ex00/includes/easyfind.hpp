#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class ValueNotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Value not found in container";
		}
};

template <typename T>
typename T::iterator	easyfind(T& container, int val)
{
	typename T::iterator	res = std::find(container.begin(), container.end(), val);
	if (res == container.end())
	{
		throw ValueNotFound();
	}
	return res;
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, int val)
{
	typename T::const_iterator res = std::find(container.begin(), container.end(), val);
	if (res == container.end())
		throw ValueNotFound();
	return res;
}

#endif
