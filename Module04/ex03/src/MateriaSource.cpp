#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	std::cout << "MateriaSource: Copy Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor Called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "MateriaSource: Operator Called" << std::endl;
	return (*this);
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	if (type.compare("ice"))
		return (new Ice());
	else if (type.compare("cure"))
		return (new Cure());
	return (NULL);
}

void MateriaSource::learnMateria(AMateria *m)
{
	(void)m;
}


