#include "Data.hpp"

Data::Data() : _value(0)
{
	std::cout << "Data: Default Constructor Called" << std::endl;
}

Data::Data(int value) : _value(value)
{
	std::cout << "Data: Parameter Constructor Called" << std::endl;
}

Data::Data(const Data &other)
{
	*this = other;
	std::cout << "Data: Copy Constructor Called" << std::endl;
}

Data::~Data()
{
	std::cout << "Data: Destructor Called" << std::endl;
}

Data &Data::operator=(const Data &other)
{
	this->_value = other.getDataValue();
	std::cout << "Data: Operator Called" << std::endl;
	return (*this);
}

int Data::getDataValue(void) const
{
	return (this->_value);
}

