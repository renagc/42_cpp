#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <climits>
# include <limits>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		//Database
		std::map<std::string, double> _db;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void _findDate(std::string date) const;

	public:
		//Constructors and Destructors
		BitcoinExchange(const std::string & db_path);
		~BitcoinExchange();

		//Exceptions
		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ArgumentsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void printDatabase();

		double findClosestDate(std::string date);
};

#endif
