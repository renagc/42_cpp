#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		class DBException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::map<std::string, double> _db;

		void _connectDB();
		void _findDate(std::string date) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);

		double findClosestDate(std::string date);
};

#endif
