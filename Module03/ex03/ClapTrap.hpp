/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:21:12 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 22:13:56 by rgomes-c         ###   ########.fr       */
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
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap( ClapTrap const & );
		~ClapTrap();

		ClapTrap &operator=( ClapTrap const & );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		void setHitPoints( int value );
		void setEnergyPoints( int value );
		void setAttackDamage( int value );
		void setName( std::string & name );
		
		std::string &getName( void ) const;
		int getHitPoints( void ) const;
		int getEnergyPoints( void ) const;
		int getAttackDamage( void ) const;
};

#endif