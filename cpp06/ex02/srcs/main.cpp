#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main(void)
{
	Base *random = generate();
	std::cout << "--- Identify avec pointeur ---" << std::endl;
	identify(random);
	std::cout << std::endl << "--- Identify avec reference ---" << std::endl;
	identify(*random);

	std::cout << std::endl << "--- Test declaration manuelle ---" << std::endl;
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	std::cout << "Test A = ";
	identify(a);
	std::cout << std::endl;
	std::cout << "Test B = ";
	identify(*b);
	std::cout << std::endl;
	std::cout << "Test C = ";
	identify(*c);
	std::cout << std::endl;
	delete a, delete b, delete c;
	return 0;
}
