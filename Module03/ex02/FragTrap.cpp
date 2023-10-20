/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 16:19:47 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap( const std::string & name ) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " requests a high-five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setHitPoints(this->getHitPoints() - 1);
	}
	else
		std::cout << "FragTrap has: " << this->getHitPoints() << " hit points and " << this->getEnergyPoints() << " energy points. Can't Attack" << std::endl;
}
