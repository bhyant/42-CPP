#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main(void)
{
	const int	size = 10;
	Animal *animal[size];

	std::cout << "--- Creation de l'array ---" << std::endl << std::endl;
	for(int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << "--- Animal Sound ---" << std::endl << std::endl;
	for (int i = 0; i < size; i++)
		animal[i]->makeSound();
	std::cout << "--- Destruction de l'array" << std::endl << std::endl;
	for (int i = 0; i < size; i++)
		delete animal[i];
	std::cout << "--- Test Deep copy ---" << std::endl << std::endl;
	Dog	original;
	Cat copy;
	original.getBrain()->setIdea(0, "I love Bones");
	*copy.getBrain() = *original.getBrain();
	std::cout << "Original Idea: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Idea: " << copy.getBrain()->getIdea(0) << std::endl;
	copy.getBrain()->setIdea(0, "I love Fish");
	std::cout << "Original Idea: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Idea: " << copy.getBrain()->getIdea(0) << std::endl << std::endl;
	std::cout << "--- Destruction ---" << std::endl;
	return 0;
}
