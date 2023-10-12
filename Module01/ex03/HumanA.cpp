/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:55:52 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 16:28:42 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon)
{
	this->_name = name;
	std::cout << "HumanA Constructor Called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA Destructor Called" << std::endl;
}

void HumanA::attack( void )
{
	if (!this->_weapon.getType().empty())
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << "Error: " << this->_name << " has no weapon type" << std::endl;
}