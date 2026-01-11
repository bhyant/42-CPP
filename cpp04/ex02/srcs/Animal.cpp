#include "../includes/Animal.hpp"
#include <string>

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Animal copy asignment called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}
