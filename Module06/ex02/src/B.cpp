#include "B.hpp"

B::B()
{
	std::cout << "B: Default Constructor Called" << std::endl;
}

B::B(const B &other)
{
	*this = other;
	std::cout << "B: Copy Constructor Called" << std::endl;
}

B::~B()
{
	std::cout << "B: Destructor Called" << std::endl;
}

B &B::operator=(const B &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "B: Operator Called" << std::endl;
	return (*this);
}

