#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog	&Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound()
{
	std::cout << "Wouaf! Wouaf!" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return this->_brain;
}
