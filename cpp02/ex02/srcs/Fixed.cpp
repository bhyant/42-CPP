#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

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

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->getRawBits() == other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;
	res.setRawBits(this->getRawBits() + other.getRawBits());
	return res;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;
	res.setRawBits(this->getRawBits() - other.getRawBits());
	return res;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}


void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
