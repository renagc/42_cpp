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

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap: Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), _name(name)
{
	this->FragTrap::_hitpoints = 100;
	this->ScavTrap::_energypoints = 50;
	this->FragTrap::_attackdmg = 30;
	std::cout << "DiamondTrap " << name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & other ) : ClapTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap: Copy Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	this->_name = other.getName();
	this->_attackdmg = other.getAttackDamage();
	this->_energypoints = other.getEnergyPoints();
	this->_hitpoints = other.getHitPoints();
	std::cout << "DiamondTrap: Operator Called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}

const std::string &DiamondTrap::getName( void ) const
{
	return (this->_name);
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}
