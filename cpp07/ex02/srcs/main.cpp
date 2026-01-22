#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "--- TEST SIMPLE ---" << std::endl;
	Array<int> array(10);
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = i;
	std::cout << "Array content: ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
	std::cout << std::endl << "--- TEST Deep copy ---" << std::endl;
	Array<int> copy(array);
	copy[0] = 999;
	std::cout << "OG: " << array[0] << std::endl;
	std::cout << "Copy: " << copy[0] << std::endl;
	std::cout << std::endl << "--- TEST Exception ---" << std::endl;
	try 
	{
		std::cout << array[100] << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}
