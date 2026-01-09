#include "../includes/ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creation ---" << std::endl;
    ScavTrap bob("Bob");

    std::cout << "\n--- Actions ---" << std::endl;
    bob.attack("Enemy");
    bob.takeDamage(30);
    bob.beRepaired(20);
    bob.guardGate();

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}
