/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:22:46 by tbhuiyan          #+#    #+#             */
/*   Updated: 2026/01/11 10:28:25 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap "  << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy Assignement called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoint = src._hitPoint;
		this->_energyPoint = src._energyPoint;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoint == 0 || this->_hitPoint == 0)
		 std::cout << "ClapTrap " << this->_name << " can't attack" << std::endl;
	else
	{
		this->_energyPoint--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
	else
	{
		if (this->_hitPoint <= (int)amount)
			this->_hitPoint = 0;
		else
			this->_hitPoint -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage HP left: " << this->_hitPoint << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint == 0 || this->_energyPoint == 0)
		std::cout << "ClapTrap " << this->_name << " can't be repaired" << std::endl;
	else
	{
		this->_energyPoint--;
		this->_hitPoint += amount;
		std::cout << "ClapTrap " << this->_name << " heal itself of " << amount << " HP. HP left: " << this->_hitPoint << std::endl;
	}
}
