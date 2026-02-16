#include "../includes/Span.hpp"

Span::Span() : _max(0), _array(0)
{}

Span::Span(unsigned int n) : _max(n)
{
	this->_array.reserve(n);
}

Span::Span(const Span& src) : _max(src._max), _array(src._array)
{
}

Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		this->_max = src._max;
		this->_array = src._array;
	}
	return *this;
}

Span::~Span()
{
}

const char* Span::SpanIsFull::what() const throw()
{
	return "Span is Full";
}

const char* Span::IncorectSpanSize::what() const throw()
{
	return "You must be add 2 value to calculate Span";
}

void Span::addNumber(int n)
{
	if (this->_array.size() >= _max)
		throw SpanIsFull();
	this->_array.push_back(n);
}

unsigned int Span::longestSpan() const
{
	if (this->_array.size() < 2)
		throw IncorectSpanSize();
	int min = *std::min_element(this->_array.begin(), this->_array.end());
	int max = *std::max_element(this->_array.begin(), this->_array.end());
	return (max - min);
}

unsigned int	Span::shortestSpan() const
{
	if (this->_array.size() < 2)
		throw IncorectSpanSize();
	std::vector<int> sorted = this->_array;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = sorted[1] - sorted[0];
	for (unsigned int i = 0; i < sorted.size() - 1; i++)
	{
		unsigned int currentSpan = sorted[i + 1] - sorted[i];
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	return minSpan;
}
