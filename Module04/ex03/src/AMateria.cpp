#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

AMateria::AMateria()
{
	this->type = "(no type)";
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria: Copy Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor Called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->type = other.getType();
	std::cout << "AMateria: Operator Called" << std::endl;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "(new undifined materia from " << target.getName() << " )" << std::endl;
}

