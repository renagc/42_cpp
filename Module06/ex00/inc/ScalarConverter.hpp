#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);

		static void convert(const std::string& literal);
};

#endif
