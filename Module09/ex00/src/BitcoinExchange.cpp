#include "../inc/BitcoinExchange.hpp"
#include <iostream>
# include <fstream>
#include <string>
# include <limits>

const char * BitcoinExchange::DBException::what() const throw()
{
	return ("Failed to get db");
}

void BitcoinExchange::_connectDB()
{
	std::ifstream file;
	file.open("src/data.csv");
	if (!file.is_open())
		throw BitcoinExchange::DBException();

	std::string line;
	std::getline(file, line);
	while (1)
	{
		std::getline(file, line);
		if (line.empty())
			break;
		this->_db[line.substr(0, line.find(','))] = std::stod(line.substr(line.find(',') + 1, line.length()));
	}
}

BitcoinExchange::BitcoinExchange()
{
	this->_connectDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	std::cout << "BitcoinExchange: Operator Called" << std::endl;
	return (*this);
}

double BitcoinExchange::findClosestDate(std::string date)
{
	std::map<std::string, double>::iterator it;
	double min = INT_MAX;
	for (it = this->_db.begin(); it != this->_db.end(); it++)
	{
		if (!it->first.find(date))
			return (it->second);
		else
		{
			size_t i;
			for (i = 0; i < date.length(); i++)
				if (date.at(i) != it->first.at(i))
					break;
			if (min > date.at(i) - it->first.at(i))
				min = it->second;
		}
	}
	return (min);
}


std::ifstream connectDB(char *path)
{
	std::ifstream file;
	file.open(path);
	return (file);
}

