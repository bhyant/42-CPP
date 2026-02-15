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
		Span();
		Span(unsigned int n);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();
		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename T>
		void	addRange(T begin, T end)
		{
			unsigned int size = std::distance(begin, end);

			if (this->_array.size() + size > this->_max)
				throw SpanIsFull();
			this->_array.insert(this->_array.end(), begin, end);
		}

		class SpanIsFull : public std::exception
		{
			virtual const char* what() const throw();
		};

		class IncorectSpanSize : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
