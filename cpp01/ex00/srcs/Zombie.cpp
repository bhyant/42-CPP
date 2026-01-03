#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Zombie";
	std::cout << this->name << "Has been created" << std::endl;
}
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << "Has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << "been destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie(std::string name)
{
	return new Zombie(name);
}

void	randomChump(std::string name)
{
	Zombie	 stack(name);
	stack.announce();
}
