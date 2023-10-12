/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:51:52 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 16:25:36 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_H
# define HumanA_H

#include <iostream>

class HumanA
{
	private:
		Weapon& _weapon;
		std::string _name;
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();
		void attack( void );
};

#endif