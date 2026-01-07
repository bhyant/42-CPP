#include "../includes/Fixed.hpp"
#include <fstream>

Fixed::Fixed()
{
	std::cout << "Constructor called" << std::endl;
	_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignement called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)roundf(n * (1 << _fractionalBits));
}

int	Fixed::toInt() const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float)this->_fixedPointValue / (float)(1 << _fractionalBits));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}

