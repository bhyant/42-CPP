#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    
    Intern intern;
    Bureaucrat boss("Boss", 1);
    
    std::cout << "\n=== Test 1: Shrubbery creation ===" << std::endl;
    try
    {
        AForm* form1 = intern.makeForm("Shrubbery request", "home");
        std::cout << *form1 << std::endl;
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Robotomy request ===" << std::endl;
    try
    {
        AForm* form2 = intern.makeForm("Robotomy request", "Bender");
        std::cout << *form2 << std::endl;
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3: Presidential pardon ===" << std::endl;
    try
    {
        AForm* form3 = intern.makeForm("Presidential Pardon", "Arthur Dent");
        std::cout << *form3 << std::endl;
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4: Unknown form ===" << std::endl;
    try
    {
        AForm* form4 = intern.makeForm("unknown form", "target");
        // Cette ligne ne sera jamais atteinte
        delete form4;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
