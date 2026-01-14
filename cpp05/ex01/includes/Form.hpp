#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form	&operator=(const Form &src);
		std::string	getName() const;
		bool		isSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(const Bureaucrat &bureaucrat);
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
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif
