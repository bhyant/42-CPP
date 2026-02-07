#include "../includes/ScalarConvertor.hpp"
#include <cstdlib>
#include <limits>
#include <string>

ScalarConvertor::ScalarConvertor()
{
}

ScalarConvertor::ScalarConvertor(const ScalarConvertor &src)
{
	(void)src;
}

ScalarConvertor &ScalarConvertor::operator=(const ScalarConvertor &src)
{
	(void)src;
	return *this;
}

ScalarConvertor::~ScalarConvertor()
{
}

bool	ScalarConvertor::isSimpleChar(const std::string &val)
{
	if (val.length() == 3 && val[0] == '\'' && val[2] == '\'')
		return true;
	return false;
}

double	ScalarConvertor::convertToDouble(const std::string &input)
{
	if (isSimpleChar(input))
		return static_cast<double>(input[1]);
	if (input == "nan" || input == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
		return std::numeric_limits<double>::infinity();
	if (input == "-inf" || input == "-inff")
		return -std::numeric_limits<double>::infinity();
	std::string	normalval = input;
	if (!normalval.empty() && normalval[normalval.length() - 1] == 'f')
		normalval = normalval.substr(0, normalval.length() - 1);
	char	*endPtr;
	double	value = std::strtod(normalval.c_str(), &endPtr);
	if (*endPtr != '\0')
	{
		std::cerr << "Error: Invalid literal" << std::endl;
		return 0.0;
	}
	return value;
}

void	ScalarConvertor::printChar(double val)
{
	std::cout << "char: ";
	if (val < 0 || val > 127 || std::isnan(val) || std::isinf(val))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(val);
	if (!std::isprint(c))
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConvertor::printInt(double val)
{
	std::cout << "int: ";
	if (val < INT_MIN || val > INT_MAX || std::isnan(val) || std::isinf(val))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(val) << std::endl;
}

void	ScalarConvertor::printFloat(double val)
{
	std::cout << "float: ";
	float res = static_cast<float>(val);
	if (std::isnan(val))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(val))
	{
		if (val > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return ;
	}
	std::cout << res;
	if (res == static_cast<int>(res))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	ScalarConvertor::printDouble(double val)
{
	std::cout << "double: ";
	if (std::isnan(val))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(val))
	{
		if (val > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return ;
	}
	std::cout << val;
	if (val == static_cast<int>(val))
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConvertor::convert(const std::string &input)
{
	if (!convertToDouble(input))
		return ;

	double val = convertToDouble(input);
	printChar(val);
	printInt(val);
	printDouble(val);
	printFloat(val);
}
