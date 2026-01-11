#include "../includes/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	this->_name = src._name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->_name = src._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << this->_name << " and my ClapTrap name is: " << ClapTrap::_name << std::endl;
}
