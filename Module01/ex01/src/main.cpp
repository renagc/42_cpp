/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:15:02 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 15:42:13 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int N = 10;
	Zombie *zombie;
	zombie = zombieHorde(N, "horde of Zombies");
	for(int i = 0; i < N; i++)
	{
		std::cout << i << ": ";
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}
