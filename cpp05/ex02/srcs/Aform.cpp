#include "../includes/Aform.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "AForm: " << this->_name << " created" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _gradeToSign(signGrade), _gradeToExec(execGrade) 
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
	std::cout << "Aform: " << this->_name << " created" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExec)
{
	std::cout << "Aform copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &src)
{
	if (this != &src)
    {
		this->_signed = src._signed;
    }
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm: " << this->_name << " destroyed" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _gradeToSign;
}

int AForm::getExecGrade() const
{
	return this->_gradeToExec;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{

	if (!this->_signed)
		throw FormNotSigned();
	if (executor.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	executeAction();
}

std::ostream &operator<<(std::ostream &o, AForm const &form)
{
	o << "Form " << form.getName() << ", signed: " << (form.isSigned()? "yes" : "no")
		<< ", grade to sign: " << form.getSignGrade() << ", grade to execute: " << form.getExecGrade();
	return o;
}
