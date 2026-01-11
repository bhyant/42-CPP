#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main(void)
{
	std::cout << "--- Construction ---" << std::endl << std::endl;
	Animal	animal;
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	WrongAnimal	wronganimal;
	WrongAnimal	*wrongcat = new WrongCat();
	std::cout << std::endl << "--- Sound ---" << std::endl << std::endl;
	dog->makeSound();
	cat->makeSound();
	animal.makeSound();
	std::cout << std::endl <<"--- WrongSound ---" << std::endl << std::endl;
	wronganimal.makeSound();
	wrongcat->makeSound();
	std::cout << std::endl << "--- Destruction ---" << std::endl << std::endl;
	delete dog, delete cat, delete wrongcat;
	return 0;
}
