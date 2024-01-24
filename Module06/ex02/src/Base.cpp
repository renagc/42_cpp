#include "Base.hpp"

Base::Base()
{
	std::cout << "Base: Default Constructor Called" << std::endl;
}

Base::Base(const Base &other)
{
	*this = other;
	std::cout << "Base: Copy Constructor Called" << std::endl;
}

Base::~Base()
{
	std::cout << "Base: Destructor Called" << std::endl;
}

Base &Base::operator=(const Base &other)
{
	(void)other;
	std::cout << "Base: Operator Called" << std::endl;
	return (*this);
}

