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

		double getDate(const std::string &date);
		int dateToInt(const std::string &date);
		bool allDigit(const std::string &str);
		bool isFloat(const std::string &str);
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
		class BuildDBException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ArgumentsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class InvalidFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void search(const std::string &str);
};

#endif
