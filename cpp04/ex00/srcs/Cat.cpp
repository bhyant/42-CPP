#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &src)
		Animal::operator=(src);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Meow! Meow!" << std::endl;
}
