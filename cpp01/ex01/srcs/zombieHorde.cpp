#include "../includes/Zombie.hpp"

void	Zombie::setname(std::string name)
{
	_name = name;
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setname(name);
	}
	return horde;
}
