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
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

	public:
		~ScalarConverter();
		static void convert(const std::string& literal);
};

#endif
