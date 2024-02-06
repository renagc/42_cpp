#include "../inc/BitcoinExchange.hpp"
#include <iostream>
# include <fstream>
#include <string>
# include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	std::cout << "BitcoinExchange: Operator Called" << std::endl;
	return (*this);
}

const char * BitcoinExchange::OpenFileException::what() const throw() { return ("Failed to get db"); }
const char * BitcoinExchange::BuildDBException::what() const throw() { return ("Failed to build db"); }
const char * BitcoinExchange::ArgumentsException::what() const throw() { return ("Wrong number of arguments (usage: ./btc <file_path>)"); }
const char * BitcoinExchange::InvalidFileException::what() const throw() { return ("Invalid File"); }


BitcoinExchange::BitcoinExchange(const std::string &path)
{
	std::fstream file;
	file.open(path.c_str(), std::ifstream::in);
	if (!file.is_open())
		throw OpenFileException();
	std::string line;
	std::getline(file, line);
	while (!file.eof())
	{
		std::getline(file, line);
		if (line.empty())
			break;
		this->_db[line.substr(0, line.find(','))] = std::atof((line.substr(line.find(',') + 1, line.length())).c_str());
	}
	if (_db.empty())
		throw BuildDBException();
}

int BitcoinExchange::dateToInt(const std::string &date)
{
	int year = std::atoi(date.substr(0, date.find_first_of('-')).c_str());
	int month = std::atoi(date.substr(date.find_first_of('-') + 1, date.find_last_of('-') - date.find_first_of('-') - 1).c_str());
	int day = std::atoi(date.substr(date.find_last_of('-') + 1, date.size()).c_str());
	year = year * 100 + month;
	year = year * 100 + day;
	return (year);
}

double BitcoinExchange::getDate(const std::string &date)
{
	std::map<std::string, double>::iterator it = _db.find(date);
	if (it != _db.end())
		return (it->second);

	int minDate = std::numeric_limits<double>::min();
	std::map<std::string, double>::iterator itf = _db.begin();
	for (it = _db.begin(); it != _db.end(); it++)
	{
		int tempDate = dateToInt(it->first);
		if (tempDate < dateToInt(date) && tempDate > minDate)
			itf = it;
	}
	return (itf->second);
}

bool BitcoinExchange::allDigit(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str.at(i)))
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isFloat(const std::string &str)
{
    bool dot = false;
    bool e = false;

    for (size_t i = 0; i < str.size(); i++)
    {
		if (i == 0 && str.at(i) == '-')
			continue;
        else if (!std::isdigit(str.at(i)))
		{
            if (str.at(i) == '.')
			{
                if (dot || e || i == 0 || i == str.size() - 1)
                    return false;
                dot = true;
            } else if (str.at(i) == 'e')
			{
                if (e || i == 0 || i == str.size() - 1 || str.at(i - 1) == '.')
                    return false;
                e = true;
			}
            else if (str.at(i) == 'f')
			{
                if (i != str.size() - 1 || str.at(i - 1) == 'e')
                   return false;
			}
            else
                return false;
        }
    }
    if (str.back() == 'e' || str.back() == '.')
        return false;
    return true;
}



void BitcoinExchange::search(const std::string &str)
{
	try
	{
		if (str.empty())
			throw "(empty line)";
		if (str.find(" | ") == std::string::npos)
			throw str;
		std::string date = str.substr(0, str.find_first_of(' '));
		std::string value = str.substr(str.find_last_of(' ') + 1, str.size());
		if (date.empty() || value.empty())
			throw str;
		std::string year = date.substr(0, date.find_first_of('-'));
		std::string month = date.substr(date.find_first_of('-') + 1, date.find_last_of('-') - date.find_first_of('-') - 1);
		std::string day = date.substr(date.find_last_of('-') + 1, date.size());
		if (year.empty() || month.empty() || day.empty())
			throw str;
		else if (year.size() > 4 || month.size() > 2 || day.size() > 2)
			throw str;
		else if (!(allDigit(year) && allDigit(month) && allDigit(day)))
			throw str;
		if (std::atof(year.c_str()) < 0 || std::atof(month.c_str()) < 1 || std::atof(month.c_str()) > 12 || std::atof(day.c_str()) > 31 || std::atof(day.c_str()) < 1)
			throw str;
		if (!isFloat(value))
			throw str;
		double floatValue = std::atof(value.c_str());
		if (floatValue < 0)
			throw "not a positive number.";
		if (floatValue > 1000)
			throw "too large a number.";
		std::cout << date << " => " << value << " = " << static_cast<float>(floatValue * getDate(date)) << std::endl;
	}
	catch (const char *e)
	{
		std::cout << "Error: " << e << std::endl;
	}
	catch (const std::string &s)
	{
		std::cout << "Error: bad input => " << s << std::endl;
	}
}
