/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:14:53 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 22:13:00 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	d1("dt1");
	DiamondTrap	d2("dt2");

    d1.whoAmI();
    d2.whoAmI();
	
    std::cout << "I am " << d1.getName() << " and my hit points as a DiamondTrap are " << d1.getHitPoints() << std::endl;
    std::cout << "I am " << d1.getName() << " and my energy points as a DiamondTrap are " << d1.getEnergyPoints() << std::endl;
    std::cout << "I am " << d1.getName() << " and my damage points as a DiamondTrap are " << d1.getAttackDamage() << std::endl << std::endl;
	
	std::cout << "Now for the interesting part:" << std::endl;
    d1.attack(d2.getName());
	d2.takeDamage(d1.getAttackDamage());
	d2.attack(d1.getName());
	d1.takeDamage(d2.getAttackDamage());
	d2.beRepaired(15);
	d1.attack(d2.getName());
	d2.takeDamage(d1.getAttackDamage());

	std::cout << std::endl;

	d1.guardGate();
	d1.highFivesGuys();
	
	std::cout << std::endl;
	
	d1.attack(d2.getName());
	d2.takeDamage(d1.getAttackDamage());
	d1.attack(d2.getName());
	d2.takeDamage(d1.getAttackDamage());
	d2.beRepaired(15);
	return (0);
}