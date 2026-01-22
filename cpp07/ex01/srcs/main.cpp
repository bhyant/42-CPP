#include "../iter.hpp"
#include <iostream>

void	doubleFloat(float &val)
{
	val *= 2.0f;
}

void	doubleInt(int &val)
{
	val *= 2;
}

int main(void)
{
	int intArray[] = {1 , 2, 3, 4, 5, 42};
	std::cout << "--- INT Test ---" << std::endl;
	iter(intArray, 6, print);
	std::cout << std::endl;
	iter(intArray, 6, doubleInt);
	std::cout << std::endl;
	iter(intArray, 6, print);

	std::cout << std::endl << "--- FLOAT Test ---" << std::endl;
	float floatArray[] = {12.5f, 42.42f, 1337.42};
	iter(floatArray, 3, print);
	std::cout << std::endl;
	iter(floatArray, 3, doubleFloat);
	std::cout << std::endl;
	iter(floatArray, 3, print);
	return 0;
}
