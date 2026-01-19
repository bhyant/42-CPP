#include "../includes/Intern.hpp"
#include <string>

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
	return *this;
}

AForm	*Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string	FormDB[3] = {"Shrubbery request", "Robotomy request", "Presidential Pardon"};
	AForm* (Intern::*create[3])(std::string const &) = {&Intern::createPresidential, &Intern::createShrubbery, &Intern::createRobotomy};

	for (int i = 0; i < 3; i++)
	{
		if (FormDB[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*create[i])(target);
		}
	}
	throw FormNotcorrect();
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}
