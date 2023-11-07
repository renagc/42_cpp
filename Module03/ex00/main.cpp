/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:14:53 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/06 15:17:05 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	ca;
	ClapTrap	cb("c1");
	ClapTrap	cc("c2");
	
	ca = cc;
	cb.attack(ca.getName());
	ca.takeDamage(5);
	ca.beRepaired(2);
	cb.attack(ca.getName());
	ca.takeDamage(25);
	ca.attack(cb.getName());
	ca.beRepaired(3);
	return (0);
}