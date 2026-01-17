#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <ostream>

int	main()
{
	std::cout << "--- ShrubberyCreationForm ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat Taj("Taj", 130);
		ShrubberyCreationForm shrub("42");
		std::cout << Taj << std::endl;
		std::cout << shrub << std::endl;
		Taj.signForm(shrub);
		shrub.execute(Taj);
	}
	catch (std::exception &e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
