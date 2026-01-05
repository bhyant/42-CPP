#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
	
	std::cout << "A Zombie Has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": been destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

