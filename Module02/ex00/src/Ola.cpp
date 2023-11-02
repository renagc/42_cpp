#include "Ola.hpp"

Ola::Ola()
{
	std::cout << "Ola: Constructor Called" << std::endl;
}

Ola::Ola(const Ola &other)
{
	(void)other; /*please change this*/
	std::cout << "Ola: Constructor Called" << std::endl;
}

Ola::~Ola()
{
	std::cout << "Ola: Destructor Called" << std::endl;
}

Ola &Ola::operator=(const Ola &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "Ola: Operator Called" << std::endl;
	return (*this);
}

