#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	static bool init = false;
	if (!init)
	{
		init = true;
		std::srand(std::time(NULL));
	}
	int rand = std::rand() % 3;

	switch (rand)
	{
		case 0:
			std::cout << "A Generated" << std::endl;
			return new A();
		case 1:
			std::cout << "B Generated" << std::endl;
			return new B();
		case 2:
			std::cout << "C Generated" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception&) {
		std::cout << "Unknown type" << std::endl;
	}
}
