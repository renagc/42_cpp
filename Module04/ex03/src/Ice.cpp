#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice: Default Constructor Called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	*this = other;
	std::cout << "Ice: Copy Constructor Called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice: Destructor Called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	this->type = other.getType();
	std::cout << "Ice: Operator Called" << std::endl;
	return (*this);
}

AMateria *Ice::clone() const
{
	AMateria *materia = new Ice(*this);
	return (materia);
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

