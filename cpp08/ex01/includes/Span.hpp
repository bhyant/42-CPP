#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int		_max;
		std::vector<int>	_array;
	public:
		Span(unsigned int n);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();
		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif
