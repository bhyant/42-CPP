#include "../includes/Bureaucrat.hpp"
#include "../includes/Aform.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat: " <<this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: " << this->_name << " created" << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy assignment called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: " << this->_name << " destroyed" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", Bureaucrat grade " << bureaucrat.getGrade();
	return o;
}

void	Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << this->_name << " can't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try 
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << this->_name  << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
