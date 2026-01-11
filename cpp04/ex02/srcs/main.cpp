#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main(void)
{
	std::cout << "--- Creation ---" << std::endl << std::endl;
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	//Animal Animal;
	std::cout << "--- Test Polymorphisme ---" << std::endl << std::endl;
	std::cout << "Animal type: " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "Animla type: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << "--- Destruction ---" << std::endl << std::endl;
	delete dog, delete cat;
	std::cout << std::endl << "--- Test avec Array ---" << std::endl << std::endl;
	const int size = 10;
	Animal *animal[size];
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < size; i++)
		animal[i]->makeSound();
	for (int i = 0; i < size; i++)
		delete animal[i];
	return 0;
}
