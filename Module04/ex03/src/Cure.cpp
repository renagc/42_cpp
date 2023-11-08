#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure: Default Constructor Called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
	std::cout << "Cure: Copy Constructor Called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure: Destructor Called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	this->type = other.getType();
	std::cout << "Cure: Operator Called" << std::endl;
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria *materia = new Cure(*this);
	return (materia);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
