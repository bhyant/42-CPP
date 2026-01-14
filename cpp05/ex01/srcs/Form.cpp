#include "../includes/Form.hpp"
#include <string>

Form::Form() : _name("Defaut"), _signed(false), _gradeToExec(150), _gradeToSign(150) 
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	std::cout << "Form: " << this->_name << " created" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int GradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToSign)
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
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

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}
