#ifndef WEAPON_H
#define WEAPON_H

#include <iomanip>
#include <string>

class Weapon
{
	private:
		std::string	_type;
	
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType();
		void	setType(std::string newType);

}

