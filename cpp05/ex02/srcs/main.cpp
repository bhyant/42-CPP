#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main()
{
	std::cout << "--- Creation ---" << std::endl << std::endl;
	Form test("Form", 30, 100);
	Bureaucrat taj("taj", 101);
	std::cout << std::endl << "--- Fail/Sucess Signature ---" << std::endl << std::endl;
	std::cout << taj << std::endl;
	taj.signForm(test);
	std::cout << test << std::endl;
	for (int i = 0; taj.getGrade() > 30; i++)
		taj.incrementGrade();
	std::cout << taj << std::endl;
	taj.signForm(test);
	std::cout << test << std::endl;
	std::cout << std::endl << "--- Too high/low Form ---" << std::endl << std::endl;
	try
	{
		Form error("Exceptions", 0, 100);
		std::cout << "Ligne pas visible car il y'a l'exception" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Form not created because: " << e.what() << std::endl;
	}
	return 0;
}
