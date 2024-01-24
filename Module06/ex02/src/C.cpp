#include "C.hpp"

C::C()
{
	std::cout << "C: Default Constructor Called" << std::endl;
}

C::C(const C &other)
{
	*this = other;
	std::cout << "C: Copy Constructor Called" << std::endl;
}

C::~C()
{
	std::cout << "C: Destructor Called" << std::endl;
}

C &C::operator=(const C &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "C: Operator Called" << std::endl;
	return (*this);
}

