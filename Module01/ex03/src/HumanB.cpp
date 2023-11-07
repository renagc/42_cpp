/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:55:52 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/27 15:05:40 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
	std::cout << "HumanB Constructor Called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB Destructor Called" << std::endl;
}

void HumanB::attack( void )
{
	if (this->_weapon)
	{
		if (!this->_weapon->getType().empty())
			std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
		else
			std::cout << "Error: " << this->_name << " has no weapon type" << std::endl;
	}
	else
		std::cout << "Error: " << this->_name << " has no weapon" << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}