#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
	std::cout << "ScalarConverter: Copy Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter: Destructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "ScalarConverter: Operator Called" << std::endl;
	return (*this);
}

void ScalarConverter::convert(const std::string& literal)
{
	char charResult;
	int intResult;
	float floatResult;
	double doubleResult;
	double literalResult;

	try {
		literalResult = std::stold(literal);
		if (literalResult > CHAR_MAX || literalResult < CHAR_MIN)
			throw OutOfLimitsException();
		charResult = std::stoi(literal);
		if (!std::isprint(charResult))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << charResult << "' " << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
	}
	try {
		if (literalResult > INT_MAX || literalResult < INT_MIN)
			throw OutOfLimitsException();
		intResult = std::stoi(literal);
		std::cout << "int: " << intResult << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "int: impossible" << std::endl;
	}
	try {
		floatResult = std::stof(literal);
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}
	try {
		doubleResult = std::stod(literal);
		std::cout << "double: " << doubleResult << std::endl;
	} catch (const std::exception& e) {
		std::cout << "double: impossible" << std::endl;
	}
}

const char* ScalarConverter::OutOfLimitsException::what() const throw()
{
	return ("Out of limits");
}
