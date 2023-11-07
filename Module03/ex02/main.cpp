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
	FragTrap	fa("FragTrap1");
	FragTrap	fb("FragTrap2");
	ScavTrap	sa("ScavTrap1");

	fa.attack(fb.getName());
	fb.takeDamage(fa.getAttackDamage());
	fa.attack(fb.getName());
	fb.takeDamage(fa.getAttackDamage());
	fb.highFivesGuys();
	fb.beRepaired(15);
	fa.attack(fb.getName());
	fb.takeDamage(fa.getAttackDamage());
	fb.attack(sa.getName());
	sa.takeDamage(fb.getAttackDamage());
	fb.attack(sa.getName());
	sa.takeDamage(fb.getAttackDamage());
	fb.attack(sa.getName());
	sa.takeDamage(fb.getAttackDamage());
	sa.attack(fa.getName());
	fa.takeDamage(sa.getAttackDamage());
	fb.attack(sa.getName());
	sa.takeDamage(fb.getAttackDamage());
	fb.attack(sa.getName());
	sa.takeDamage(fb.getAttackDamage());
	return (0);
}