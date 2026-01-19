#include "../includes/Convertor.hpp"
#include <cstdlib>
#include <limits>
#include <string>

Convertor::Convertor()
{
}

Convertor::Convertor(const Convertor &src)
{
	(void)src;
}

Convertor &Convertor::operator=(const Convertor &src)
{
	(void)src;
	return *this;
}

Convertor::~Convertor()
{
}

bool	Convertor::isSimpleChar(const std::string &val)
{
	if (val.length() == 3 && val[0] == '\'' && val[2] == '\'')
		return true;
	return false;
}

bool	Convertor::isLiteral(const std::string &val)
{
	if (val == "nan" || val == "nanf" || val == "+inf" || val == "-inf" || val == "+inff" || val == "-inff" || val == "inf" || val == "inff")
		return true;
	return false;
}

double	Convertor::ConvertToDouble(const std::string &val)
{
	if (isSimpleChar(val))
		return static_cast<double>(val[1]);
	if (val == "nan" || val == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (val == "+inf" || val == "+inff" || val == "inf" || val == "inff")
		return std::numeric_limits<double>::infinity();
	if (val == "-inf" || val == "-inff")
		return std::numeric_limits<double>::infinity();
	std::string	normalval = val;
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


