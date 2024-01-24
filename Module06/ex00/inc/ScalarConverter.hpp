#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	public:
		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);

		static void convert(const std::string& literal);
};

#endif
