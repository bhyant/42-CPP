#include "../includes/Bureaucrat.hpp"
#include <exception>
#include <ostream>

int	main()
{
	std::cout << "--- Creation ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat taj("Taj", 21);
		std::cout << taj << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--- Incrementation/Decrementation ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat ilan("Ilan", 100);
		std::cout << ilan << std::endl;
		ilan.incrementGrade();
		std::cout << "Apres Incrementation: " << ilan << std::endl;
		ilan.decrementGrade();
		std::cout << "Apres Decrementation: " << ilan << std::endl;
	} 
	catch (std::exception &e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--- Grade Trop Haut ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat	adel("Adel", 1);
		std::cout << adel << std::endl;
		adel.incrementGrade();
		std::cout << adel << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
