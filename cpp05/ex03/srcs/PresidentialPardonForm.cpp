#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardon created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardon created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardon copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "PresidentialPardon copy assignment called" << std::endl;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardon Form destroyed" << std::endl;
}
