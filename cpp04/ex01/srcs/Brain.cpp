#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &src)
{
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int i, const std::string &idea)
{
	if (i >= 0 && i < 100)
		this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return this->_ideas[i];
	return "";
}
