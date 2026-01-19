#ifndef INTERN_HPP
#define INTERN_HPP

#include "../includes/Aform.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <exception>

class Intern
{
	private:
		AForm* createShrubbery(const std::string &target);
		AForm* createPresidential(const std::string &target);
		AForm* createRobotomy(const std::string &target);
	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();
		AForm*	makeForm(const std::string &formName, const std::string &target);

		class FormNotcorrect : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Form not found";
				}
		};
};

#endif
