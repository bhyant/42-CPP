/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:45:30 by tbhuiyan          #+#    #+#             */
/*   Updated: 2026/04/23 18:58:07 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

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

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
		return false;
    if (date[4] != '-' || date[7] != '-')
		return false;
    for (size_t i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
			continue;
        if (!std::isdigit(date[i]))
			return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2009)
		return false;
    if (month < 1 || month > 12)
		return false;
    if (day < 1 || day > 31)
		return false;
    if (month == 4 || month == 6 || month == 9 || month == 11)
	{
        if (day > 30) return false;
    }
    else if (month == 2)
	{
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap && day > 29)
			return false;
        if (!isLeap && day > 28)
			return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& str, float& value) const
{
    if (str.empty())
		return false;
    size_t i = 0;
    if (str[i] == '-')
	{
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (str[i] == '+')
	{
        i++;
    }
    int dotCount = 0;
    for (; i < str.length(); ++i)
	{
        if (str[i] == '.')
		{
            dotCount++;
            if (dotCount > 1)
			{
                std::cerr << "Error: bad input => " << str << std::endl;
                return false;
            }
        }
		else if (!std::isdigit(str[i]))
		{
            std::cerr << "Error: bad input => " << str << std::endl;
            return false;
        }
    }
    value = std::atof(str.c_str());
    if (value > 1000.0f)
	{
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::initData(const std::string& str)
{
	std::ifstream file(str.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open Data file" << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find(",");
		if (sep !=  std::string::npos)
		{
			std::string date = line.substr(0, sep);
			std::string rateStr = line.substr(sep + 1);
			float rate = std::atof(rateStr.c_str());
			_data[date] = rate;
		}
	}
	file.close();
}

void BitcoinExchange::parseInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: cannot open input file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
	{
        size_t separator = line.find(" | ");
        if (separator == std::string::npos)
		{
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, separator);
        std::string valueStr = line.substr(separator + 3);
        if (!isValidDate(date))
		{
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        float value;
        if (!isValidValue(valueStr, value))
            continue;
		std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
        if (it == _data.end() || it->first != date) {
            if (it == _data.begin()) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}
