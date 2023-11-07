#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdmg(0)
{
	std::cout << "ClapTrap: Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap: Copy Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other.getName();
	this->_attackdmg = other.getAttackDamage();
	this->_energypoints = other.getHitPoints();
	this->_hitpoints = other.getHitPoints();
	std::cout << "ClapTrap: Operator Called" << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitpoints > 0 && this->_energypoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackdmg << " points of damage!" << std::endl;
		this->_energypoints--;
	}
	else
		std::cout << "ClapTrap has: " << this->_hitpoints << " hit points and " << this->_energypoints << " energy points. Can't Attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		this->_hitpoints -= amount;
		std::cout << "ClapTrap " << this->_name << " take damage for " << amount << " points of damage" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't take damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints > 0 && this->_energypoints > 0)
	{
		this->_hitpoints += amount;
		this->_energypoints--;
		std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't be repaired!" << std::endl;
}

//Accessors
const std::string &ClapTrap::getName( void ) const
{
	return (this->_name);
}

int ClapTrap::getHitPoints( void ) const
{
	return (this->_hitpoints);
}


int ClapTrap::getEnergyPoints( void ) const
{
	return (this->_energypoints);
}


int ClapTrap::getAttackDamage( void ) const
{
	return (this->_attackdmg);
}