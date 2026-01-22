#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base()
{
	std::cout << "Base destroyed" << std::endl;
}

A::~A()
{
	std::cout << "A destroyed" << std::endl;
}

B::~B()
{
	std::cout << "B destroyed" << std::endl;
}

C::~C()
{
	std::cout << "C destroyed" << std::endl;
}
