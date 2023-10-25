/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:00:11 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 15:25:10 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " Constructor Called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout<< this->_name << " Destructor Called" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
