/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:51:52 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 16:33:19 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_H
# define HumanB_H

#include <iostream>

class HumanB
{
	private:
		Weapon* _weapon;
		std::string _name;
	public:
		HumanB( std::string name );
		~HumanB();
		void attack( void );
		void setWeapon( Weapon& weapon );
};

#endif