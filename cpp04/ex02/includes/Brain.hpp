#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &src);
		Brain	&operator=(const Brain &src);
		~Brain();
		void	setIdea(int i, const std::string &idea);
		std::string	getIdea(int i) const;
};

#endif
