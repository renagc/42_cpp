/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:56:14 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/13 11:52:37 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_lvls[0] = "DEBUG";
	_lvls[1] = "INFO";
	_lvls[2] = "WARNING";
	_lvls[3] = "ERROR";
	std::cout << "Constructor Called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor Called" << std::endl;
}

void Harl::_debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*ptr[4])(void);
	
	ptr[0] = &Harl::_debug;
	ptr[1] = &Harl::_info;
	ptr[2] = &Harl::_warning;
	ptr[3] = &Harl::_error;

	int choice = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(this->_lvls[i]))
		{
			choice = i + 1;
			break ;
		}
	}
	switch (choice)
	{
        case 1:
			(this->*ptr[0])();
        case 2:
			(this->*ptr[1])();
        case 3:
			(this->*ptr[2])();
		case 4:
			(this->*ptr[3])();
        default:
            std::cout << "Invalid choice." << std::endl;
    }
}