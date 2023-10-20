/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/19 15:25:00 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap has been created!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	this->FragTrap::setHitPoints(100);
	this->ScavTrap::setEnergyPoints(50);
	this->FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap " << name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & other ) : ClapTrap(other)
{
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << "none" << std::endl;
}
