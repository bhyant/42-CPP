#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));  // Pour le random de RobotomyRequestForm
    
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);  // Crée le fichier home_shrubbery
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << alice << std::endl;
        std::cout << robot << std::endl;
        
        alice.signForm(robot);
        alice.executeForm(robot);  // 50% chance
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Form non signée ===" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm unsigned_form("test");
        
        boss.executeForm(unsigned_form);  // ❌ Pas signé
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 5: Grade trop bas pour exécuter ===" << std::endl;
    try
    {
        Bureaucrat lowGrade("LowGrade", 50);
        PresidentialPardonForm pardon("Criminal");
        
        Bureaucrat signer("Signer", 20);
        signer.signForm(pardon);
        
        lowGrade.executeForm(pardon);  // ❌ Grade 50 > 5 requis
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
