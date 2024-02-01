#include "../inc/BitcoinExchange.hpp"
#include <iostream>
# include <fstream>
#include <string>
# include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	std::cout << "BitcoinExchange: Operator Called" << std::endl;
	return (*this);
}

const char * BitcoinExchange::OpenFileException::what() const throw() { return ("Failed to get db"); }

const char * BitcoinExchange::ArgumentsException::what() const throw() { return ("Failed"); }

BitcoinExchange::BitcoinExchange(const std::string &path)
{
	std::fstream file;
	file.open(path.c_str(), std::ifstream::in);
	if (!file.is_open())
		throw OpenFileException();
	std::string line;
	std::getline(file, line);
	while (1)
	{
		std::getline(file, line);
		if (line.empty())
			break;
		this->_db[line.substr(0, line.find(','))] = std::atof((line.substr(line.find(',') + 1, line.length())).c_str());
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) { *this = other; }

void BitcoinExchange::printDatabase()
{
	std::map<std::string, double>::iterator it = _db.begin();
	for (; it != _db.end(); it++)
		std::cout << "date: " << it->first << std::endl << "value: " << it->second << std::endl;
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
