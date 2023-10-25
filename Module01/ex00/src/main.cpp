/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:15:02 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 15:23:16 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie *zombie;

	zombie = newZombie("foo");
	randomChump("foo2");
	zombie->announce();
	delete zombie;
	return (0);
}
