#include "A.hpp"

A::A()
{
	std::cout << "A: Default Constructor Called" << std::endl;
}

A::A(const A &other)
{
	*this = other;
	std::cout << "A: Copy Constructor Called" << std::endl;
}

A::~A()
{
	std::cout << "A: Destructor Called" << std::endl;
}

A &A::operator=(const A &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "A: Operator Called" << std::endl;
	return (*this);
}

