#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		AForm	&operator=(const AForm &src);
		virtual ~AForm();
		std::string	getName() const;
		bool		isSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(const Bureaucrat &executor) const;
		virtual void	executeAction() const = 0;
		class GradeTooHighException : public std::exception
    	{
			public:
				virtual const char* what() const throw()
				{
					return "Grade too high";
				}
		};
		class GradeTooLowException : public std::exception
		{
    		public:
        		virtual const char* what() const throw()
				{
					return "Grade too low";
				}
    	};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Form is not signed";
				}
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif
