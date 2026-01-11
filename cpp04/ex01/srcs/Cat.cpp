#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound()
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return this->_brain;
}
