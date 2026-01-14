#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main()
{
	std::cout << "--- Creation ---" << std::endl << std::endl;
	Form test("Form", 30, 100);
	Bureaucrat taj("taj", 101);
	std::cout << std::endl << "--- Fail Signature ---" << std::endl << std::endl;
	taj.signForm(test);
	
	return 0;
}
