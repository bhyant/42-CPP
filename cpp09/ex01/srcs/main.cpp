#include "../includes/RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Wrong number of args." << std::endl;
		return 1;
	}
	RPN	calculator;
	calculator.calculate(av[1]);
	return 0;
}
