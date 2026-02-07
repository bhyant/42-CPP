#include "../includes/Convertor.hpp"

int	main(int ac,char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Wrong number of args" << std::endl;
		return 1;
	}
	ScalarConvertor::convert(av[1]);
	return 0;
}
