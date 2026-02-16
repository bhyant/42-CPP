#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _data(src._data)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		this->_data = src._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::checkDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::string stryear = date.substr(0, 4);
	std::string strmonth = date.substr(5, 2);
	std::string strday = date.substr(8, 2);
	int year = std::atoi(stryear.c_str());
	int month = std::atoi(strmonth.c_str());
	int day = std::atoi(strday.c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	return true;
}
