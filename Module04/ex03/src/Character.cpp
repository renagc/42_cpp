#include "Character.hpp"

Character::Character()
{
}
Character::Character(std::string name) : _name(name) 
{	
	std::cout << "ola" << std::endl;
	_name = name;
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout << "Character: Copy Constructor Called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character: Destructor Called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	this->m[0] = other.m[0];
	this->m[1] = other.m[1];
	this->m[2] = other.m[2];
	this->m[3] = other.m[3];
	this->_name = other._name;
	std::cout << "Character: Operator Called" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	(void)m;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
}

void Character::unequip(int idx)
{
	this->m[idx] = NULL;
}

