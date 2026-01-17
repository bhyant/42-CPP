#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Aform.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		std::string	getTarget() const;
		virtual void	executeAction() const;
};

#endif
