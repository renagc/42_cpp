/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:14:53 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 15:25:56 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("ClappTrack");

	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(2);
	clap.attack("Enemy2");
	return (0);
}