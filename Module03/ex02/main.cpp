/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:14:53 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 16:24:37 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	Blert("Blert");
	FragTrap	Forty("Fortytuos");
	ScavTrap	Dynamo("Dynamo");

	Blert.attack(Forty.getName());
	Forty.takeDamage(Blert.getAttackDamage());
	Blert.attack(Forty.getName());
	Forty.takeDamage(Blert.getAttackDamage());
	Forty.highFivesGuys();
	Forty.beRepaired(15);
	Blert.attack(Forty.getName());
	Forty.takeDamage(Blert.getAttackDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getAttackDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getAttackDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getAttackDamage());
	Dynamo.attack(Blert.getName());
	Blert.takeDamage(Dynamo.getAttackDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getAttackDamage());
	Forty.attack(Dynamo.getName());
	Dynamo.takeDamage(Forty.getAttackDamage());
	return (0);
}