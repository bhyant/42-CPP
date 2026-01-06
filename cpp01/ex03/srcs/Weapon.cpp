#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

const  std::string&	 Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}


