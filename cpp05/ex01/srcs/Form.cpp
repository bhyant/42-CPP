#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <ostream>

Form::Form() : _name("Defaut"), _signed(false), _gradeToSign(150), _gradeToExec(150) 
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	std::cout << "Form: " << this->_name << " created" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
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

Form::~Form()
{
	std::cout << "Form: " << this->_name << " destroyed" << std::endl;
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

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "Form: " << form.getName() << " , are " << (form.isSigned() ? "signed" : "not signed") 
		<< " , grade to sign: " << form.getSignGrade() << " , grade to execute: " << form.getExecGrade() << std::endl;
	return o;
}
