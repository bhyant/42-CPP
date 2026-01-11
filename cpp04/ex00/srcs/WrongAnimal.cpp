#include "../includes/WrongAnimal.hpp"
#include <string>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "WrongAnimal copy asignment called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound()
{
	std::cout << "WrongAnimal make sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
