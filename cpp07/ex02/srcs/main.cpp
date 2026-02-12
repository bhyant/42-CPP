#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "--- Test avec std::string ---" << std::endl << std::endl;
	Array<std::string> str(3);
	str[0] = "Salut";
	str[1] = "c'est";
	str[2] = "Taj";
	for (unsigned int i = 0; i < str.size(); i++)
		std::cout << str[i] << " ";
	std::cout << std::endl << std::endl;
	std::cout << "--- Test Deep copy ---" << std::endl;
	Array<std::string> strcopy = str;
	strcopy[2] = "Adel";
	std::cout << "Original Value: " << str[2] << std::endl;
	std::cout << "Copy Value: " << strcopy[2] << std::endl;
	std::cout << std::endl << "--- Test Exception ---" << std::endl;
	try
	{
		str[100] = "test";
	} 
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}


