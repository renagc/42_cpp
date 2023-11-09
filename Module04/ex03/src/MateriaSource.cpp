#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->m[i] = NULL;
	std::cout << "MateriaSource: Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	std::cout << "MateriaSource: Copy Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i])
			delete this->m[i];
	}
	std::cout << "MateriaSource: Destructor Called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.m[i])
			this->m[i] = other.m[i]->clone();
	}
	std::cout << "MateriaSource: Operator Called" << std::endl;
	return (*this);
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i] && !type.compare(this->m[i]->getType()))
			return (this->m[i]->clone());
	}
	std::cout << "Error creating materia" << std::endl;
	return (NULL);
}

void MateriaSource::learnMateria(AMateria *m)
{
	bool learned = false;

	for (int i = 0; i < 4; i++)
	{
		if (!learned && !this->m[i])
		{
			learned = true;
			this->m[i] = m;
		}
	}
	if (!learned)
		std::cout << "Error learning materia" << std::endl;
}


