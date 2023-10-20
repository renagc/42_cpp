/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 21:59:19 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " has been created!" << std::endl;
}

FragTrap::FragTrap( const std::string & name )
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap const & other)
{
	this->setAttackDamage(other.getAttackDamage());
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " requests a high-five!" << std::endl;
}
