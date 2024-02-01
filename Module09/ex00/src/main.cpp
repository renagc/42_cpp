#include <iostream>
#include <map>
#include <iterator>
#include <cstdlib>
#include <climits>
#include "BitcoinExchange.hpp"

int verify_string(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	if (str.empty())
		return (0);
	return (1);
}

size_t find_space(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]))
			return (i);
	}
	return (-1);
}

void parseLine(std::string line, BitcoinExchange &exchange)
{
	try
	{
		{
			std::string format = line;
			std::string formatKey;
			formatKey = format.substr(0, find_space(format));
			format.erase(0, find_space(format) + 1);
			formatKey = format.substr(0, find_space(format));
			if (formatKey.compare("|"))
				throw std::invalid_argument("bad input => " + line);
		}
		{
			std::string date = line.substr(0, find_space(line));
			std::string year, month, day;
			year = date.substr(0, date.find('-'));
			date.erase(0, date.find('-') + 1);
			month = date.substr(0, date.find('-'));
			date.erase(0, date.find('-') + 1);
			day = date;
			if (!verify_string(year) || !verify_string(month) || !verify_string(day))
				throw std::invalid_argument("bad input => " + line);
			if (std::atoi(year.c_str()) > INT_MAX || std::atoi(year.c_str()) < 0 || std::atoi(month.c_str()) > 12 || std::atoi(month.c_str()) < 1 || std::atoi(day.c_str()) > 31 || std::atoi(day.c_str()) < 1)
				throw std::invalid_argument("bad input => " + line);
		}
		{
			std::string value = line.substr(line.find(' ') + 3, line.length());
			float d = std::atof(value.c_str());
			d < 0 ? throw std::invalid_argument("not a positive number.") : d;
			d > 1000 ? throw std::invalid_argument("too large a number.") : d;
			bool dot = false;
			for (size_t i = 0; i < value.length(); i++)
			{
				if (value[i] == '.' && dot == false)
					dot = true;
				else if ((value[i] == '.' && dot == true) || !std::isdigit(value[i]))
					throw std::invalid_argument("bad input => " + line);
			}
		}
		{
			std::string date = line.substr(0, line.find(' '));
			// float value = std::stod(line.substr(line.find(' ') + 2, line.length()));
			std::cout << exchange.findClosestDate(date) << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main(int ac, char **av)
{
	try
	{
		BitcoinExchange btc("src/data.csv");
		if (ac != 2)
			throw BitcoinExchange::ArgumentsException();
		(void)ac;
		(void)av;
		// btc.printDatabase();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}