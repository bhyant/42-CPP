#include "../includes/DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Creation ---" << std::endl;
    DiamondTrap diamond("Diamond");

	std::cout << "--- Actions ---" << std::endl;
	diamond.attack("Enemy");
	diamond.takeDamage(20);
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.whoAmI();

	std::cout << "--- Destruction ---" << std::endl;
}
