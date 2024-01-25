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
	double literalResult;

	literalResult = std::strtod(literal.c_str(), NULL);
	try {
		if (literalResult > CHAR_MAX || literalResult < CHAR_MIN)
			throw OutOfLimitsException();
		if (!std::isprint(static_cast<int>(literalResult)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(literalResult) << "' " << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
	}
	try {
		if (literalResult > INT_MAX || literalResult < INT_MIN)
			throw OutOfLimitsException();
		std::cout << "int: " << static_cast<int>(literalResult) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "int: impossible" << std::endl;
	}
	try {
		if (literalResult > __FLT_MAX__ || literalResult < -__FLT_MAX__)
			throw OutOfLimitsException();
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literalResult) << "f" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}
	try {
		std::cout << "double: " << literalResult << std::endl;
	} catch (const std::exception& e) {
		std::cout << "double: impossible" << std::endl;
	}
}

const char* ScalarConverter::OutOfLimitsException::what() const throw()
{
	return ("Out of limits");
}
