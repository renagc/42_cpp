/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:21:03 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 15:25:17 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdmg(0)
{
	std::cout << "Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
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