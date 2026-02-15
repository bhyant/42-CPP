#include "../includes/Span.hpp"
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << "--- Test Simple ---" << std::endl << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "--- Test Exception ---" << std::endl;
	try
	{
		std::cout << "Test Taille Max:" << std::endl;
		Span max = Span(5);
		for (int i = 0; i <= 5; i++)
			max.addNumber(i);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}
	try 
	{
		std::cout << "Test Span pas calculable:" << std::endl;
		Span min = Span(5);
		min.addNumber(50);
		std::cout << min.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}
	std::cout << "--- Test AddRange ---" << std::endl;
	std::vector<int> Rangetest(10000);
	std::generate(Rangetest.begin(), Rangetest.end(), std::rand);
	Span Range(10000);
	Range.addRange(Rangetest.begin(), Rangetest.end());
	std::cout << Range.shortestSpan() << std::endl;
	std::cout << Range.longestSpan() << std::endl;
	return 0;
}
