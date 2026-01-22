#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <string>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iostream>


class Convertor
{
	private:
		Convertor();
		Convertor(const Convertor &src);
		Convertor &operator=(const Convertor &src);
		~Convertor();
		static void	printChar(double val);
		static void printInt(double val);
		static void printFloat(double val);
		static void printDouble(double val);
		static bool isSimpleChar(const std::string &val);
		static double convertToDouble(const std::string &val);

	public:
		static void convert(const std::string &val);
};

#endif
