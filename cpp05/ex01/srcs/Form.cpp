#include "../includes/Form.hpp"
#include <string>

Form::Form() : _name("Defaut"), _signed(false), _gradeToExec(150), _gradeToSign(150) 
{
	std::cout << "Form: " << this->_name << " created" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int GradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToSign)
{
	std::cout << "Form: " << this->_name << " created" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;	
}

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::isSigned() const
{
	return this->_signed;
}

int	Form::getExecGrade() const
{
	return this->_gradeToExec;
}

int Form::getSignGrade() const
{
	return this->_gradeToSign;
}
