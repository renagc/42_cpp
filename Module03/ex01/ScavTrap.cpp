/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 15:56:31 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( const std::string & name ) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setHitPoints(this->getHitPoints() - 1);
	}
	else
		std::cout << "ScavTrap has: " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points. Can't Attack" << std::endl;
}
