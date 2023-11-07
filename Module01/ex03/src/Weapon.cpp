/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:55:52 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 16:13:29 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string name ) : _name(name)
{
	std::cout << "Weapon Constructor Called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon Destructor Called" << std::endl;
}

std::string const& Weapon::getType( void )
{
	return (this->_type);
}

void Weapon::setType( std::string type )
{
	this->_type = type;
}