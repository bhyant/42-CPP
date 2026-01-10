#include "../includes/FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- FragTrap ---" << std::endl;
    FragTrap frag;
    
    frag.attack("Enemy");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}
