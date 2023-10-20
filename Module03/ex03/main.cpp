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
	std::string	One = "One";
	std::string	Two = "Two";
	
	DiamondTrap	D1(One);
	DiamondTrap	D2(Two);

    D1.whoAmI();
    D2.whoAmI();
	
    std::cout << "I am " << D1.getName() << " and my hit points as a DiamondTrap are " << D1.getHitPoints() << std::endl;
    std::cout << "I am " << D1.getName() << " and my energy points as a DiamondTrap are " << D1.getEnergyPoints() << std::endl;
    std::cout << "I am " << D1.getName() << " and my damage points as a DiamondTrap are " << D1.getDamage() << std::endl << std::endl;
	
	std::cout << "Now for the interesting part:" << std::endl;
    D1.attack(Two);
	D2.takeDamage(D1.getDamage());
	D2.attack(One);
	D1.takeDamage(D2.getDamage());
	D2.beRepaired(15);
	D1.attack(Two);
	D2.takeDamage(D1.getDamage());

	std::cout << std::endl;

	D1.guardGate();
	D1.highFivesGuys();
	
	std::cout << std::endl;
	
	D1.attack(Two);
	D2.takeDamage(D1.getDamage());
	D1.attack(Two);
	D2.takeDamage(D1.getDamage());
	D2.beRepaired(15);
	return (0);
}