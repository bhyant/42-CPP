#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "Adresse de la variable :" << &brain << std::endl;
	std::cout << "Adresse du pointeur :" << stringPTR << std::endl;
	std::cout << "Adresse de la reference :" << &stringREF << std::endl;
}
