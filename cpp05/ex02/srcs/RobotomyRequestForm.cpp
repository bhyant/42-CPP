#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <string>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm created" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << "RobotomyRequest copy constructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "Robotomy copy assignment called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequest destructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "BZZZZZZZZZZZZZZZ * Some drilling noise * BZZZZZZZZZZZ" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has beem rotomized sucessfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << std::endl;
}
