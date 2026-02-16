#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		bool	parseInput(const std::string& filename) const;
		bool	checkDate(const std::string& data) const;
		bool	checkValue(float value) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
		void	loadDB(const std::string& filename);
		void	processInput(const std::string& filename);

};
