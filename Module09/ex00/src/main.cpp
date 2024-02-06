#include <iostream>
#include <map>
#include <iterator>
#include <cstdlib>
#include <climits>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		BitcoinExchange btc("src/data.csv");
		if (ac != 2)
			throw BitcoinExchange::ArgumentsException();
		(void)ac;
		(void)av;
		std::fstream file;
		file.open(av[1], std::ifstream::in);
		if (!file.is_open())
			throw BitcoinExchange::InvalidFileException();
		std::string line;
		std::getline(file, line);
		while (!file.eof())
		{
			std::getline(file, line);
			btc.search(line);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}