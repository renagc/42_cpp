#include "Character.hpp"

Character::Character()
{
	this->list = new LinkedList();
	for (int i = 0; i < 4; i++)
		this->_m[i] = NULL;
}
Character::Character(std::string name) : _name(name)
{
	this->list = new LinkedList();
	for (int i = 0; i < 4; i++)
		this->_m[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout << "Character: Copy Constructor Called" << std::endl;
}

Character::~Character()
{
	delete this->list;
	std::cout << "Character: Destructor Called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_m[i])
			delete this->_m[i];
		if (this->_m[i])
			this->_m[i] = other._m[i];
		else
			this->_m[i] = NULL;
	}
	this->_name = other._name;
	this->list = other.list;
	std::cout << "Character: Operator Called" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	bool	equiped = false;

	if (!m)
		std::cout << "(empty materia)" << std::endl;
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (!equiped && !this->_m[i])
			{
				std::cout << "Equipped " << m->getType() << " at slot " << i << std::endl;
				this->_m[i] = m;
				equiped = true;
			}
		}
		if (!equiped)
		{
			std::cout << "Error: inventory full" << std::endl;
			delete m;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Error use invalid" << std::endl;
	else if (!this->_m[idx])
		std::cout << "Error use empty" << std::endl;
	else
		this->_m[idx]->use(target);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Error unequip invalid" << std::endl;
	else if (!this->_m[idx])
		std::cout << "Error unequip empty" << std::endl;
	else
	{
		std::cout << "Unequiped" << std::endl;
		this->list->newList(this->_m[idx]);
		this->_m[idx] = NULL;
	}
}

