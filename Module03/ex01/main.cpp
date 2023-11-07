/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:14:53 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:57 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	sa;
	ScavTrap	sb("ScavTrap1");
	ScavTrap	sc("ScavTrap2");
	
	sa = sc;
	sb.attack(sa.getName());
	sa.takeDamage(50);
	sa.beRepaired(20);
	sb.attack(sa.getName());
	sa.takeDamage(250);
	sa.attack(sb.getName());
	sa.beRepaired(1);
	return (0);
}