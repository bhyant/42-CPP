#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreation created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreation created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreation copy constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "ShrubberyCreation copy assignment called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreation destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cout << "Error : cannot create file " << filename << std::endl;
		return ;
	}
	file
	<< "        *                *\n"
	<< "       ***              ***\n"
	<< "      *****            *****\n"
	<< "     *******          *******\n"
	<< "    *********        *********\n"
	<< "   ***********      ***********\n"
	<< "  *************    *************\n"
	<< "       | |              | |\n"
	<< "       | |              | |"
	<< std::endl;
	file.close();
	std::cout << "Shrubbery created in " << filename << std::endl;
}
