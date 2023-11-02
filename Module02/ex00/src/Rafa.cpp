#include "Rafa.hpp"

Rafa::Rafa()
{
	std::cout << "Rafa: Constructor Called" << std::endl;
}

Rafa::Rafa(const Rafa &other)
{
	(void)other; /*please change this*/
	std::cout << "Rafa: Constructor Called" << std::endl;
}

Rafa::~Rafa()
{
	std::cout << "Rafa: Destructor Called" << std::endl;
}

Rafa &Rafa::operator=(const Rafa &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "Rafa: Operator Called" << std::endl;
	return (*this);
}

