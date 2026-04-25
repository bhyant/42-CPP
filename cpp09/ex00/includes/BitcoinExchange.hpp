#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void initData(const std::string& str);
		void parseInput(const std::string& str);

	private:
		std::map<std::string, float> _data;
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& str, float& value) const;
};
