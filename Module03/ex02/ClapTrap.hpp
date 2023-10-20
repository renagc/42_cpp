/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:21:12 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 15:52:33 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	private:
		std::string 	_name;
		int				_hitpoints;
		int				_energypoints;
		int				_attackdmg;
	
	public:
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		void setHitPoints( int value );
		void setEnergyPoints( int value );
		void setAttackDamage( int value );
		
		std::string &getName( void );
		int getHitPoints( void );
		int getEnergyPoints( void );
		int getAttackDamage( void );
};

#endif