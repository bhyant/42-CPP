#include "../includes/WrongCat.hpp"
#include <string>

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &src)
		WrongAnimal::operator=(src);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound()
{
	std::cout << "Meow! Meow!" << std::endl;
}
