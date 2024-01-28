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

void ScalarConverter::convert(const std::string& input)
{
	std::string limits[8] = {"inf", "+inf", "-inf", "inff", "+inff", "-inff", "nan", "nanf"};
	bool is_inf = false;
	bool is_nan = false;
	bool is_valid = true;

	if (input.find_first_not_of("0123456789+-.ef") != std::string::npos)
	{
		bool is_limit = false;
		for (int i = 0; i < 8; i++)
			if (!limits[i].compare(input))
				is_limit = true;
		if (!is_limit)
			is_valid = false;
	}
	else if (input.find_first_of("ef") == 0)
		is_valid = false;
	else if (input.find_first_of("+-") == 0 && !std::isdigit(input.at(1)) && input.at(1) != '.')
		is_valid = false;
	if (input.find('.') != std::string::npos)
	{
		if (input.find('f') != std::string::npos)
			input.substr(0, input.size() - 1);
	}
	else
	{
		if (input.find("inf") != std::string::npos)
			is_inf = true;
		else if (input.find("nan") != std::string::npos)
			is_nan = true;
	}

	double value = std::atof(input.c_str());

	 // Convert to char
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && is_valid) {
		char c = static_cast<char>(value);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	// Convert to int
	if (!is_nan && !is_inf && is_valid && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && input.at(0) != '.') {
		if ((input.at(0) == '-' || input.at(0) == '+') && input.at(1) == '.')
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl;
	}

	// Convert to float
	if (!is_nan && is_valid) {
		float f = (is_inf ? (input[0] == '-' ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity()) : static_cast<float>(value));
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else if (is_nan && is_valid)
		std::cout << "float: " << "nanf" << std::endl;
	else {
		std::cout << "float: impossible" << std::endl;
	}

	// Convert to double
	if (!is_nan && is_valid) {
		double d = is_inf ? (input[0] == '-' ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity()) : value;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (is_nan && is_valid){
		std::cout << "float: " << "nan" << std::endl;
	}
	else {
		std::cout << "double: impossible" << std::endl;
	}
}
