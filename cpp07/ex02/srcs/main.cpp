#include <iostream>
#include "../includes/Array.hpp"

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
	std::cout << "--- Test avec int ---" << std::endl;
	Array<int> intarray(10);
	for (unsigned int i = 0; i < intarray.size(); i++)
	{
		intarray[i] = i * 2;
		std::cout << "Value[" << i << "]: " << intarray[i] << std::endl;
	}
	std::cout << "--- Test Size() ---" << std::endl;
	std::cout << "str size: " << str.size() << std::endl;
	std::cout << "intarray size: " << intarray.size() << std::endl;
	return 0;
}

// #include <stdlib.h>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
