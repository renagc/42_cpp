/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:09:00 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/25 12:46:41 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor Called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor Called" << std::endl;
}

void	PhoneBook::searchContact(int index)
{
	std::string prompt;

	if (index == 0)
	{
		std::cout << "no contacts on this list" << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << "Index" << " | " << std::setw(10) << "First Name" << " | " << std::setw(10) << "Last Name" << " | " << std::setw(10) << "Nickname" << std::setw(10) << std::endl;
	for (int i = 0; i < index; i++)
	{
		std::cout << std::right << std::setw(10) << i << " | ";
		this->_contacts[i].displayPrivate();
	}
	while (1)
	{
		std::cout << "Choose one contact index to display: ";
		getline(std::cin, prompt);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		if (prompt.length() == 1 && std::isdigit(prompt.at(0)) && std::atoi(prompt.c_str()) < index)
		{
			this->_contacts[std::atoi(prompt.c_str())].showPrivate();
			return ;
		}
		else
			std::cout << "Wrong Number!" << std::endl;
	}
}

// void PhoneBook::fillList(void)
// {
// 	this->_contacts[0].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[1].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[2].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[3].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[4].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[5].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[6].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// 	this->_contacts[7].addContact("Renato", "Couto", "Nick", "Number", "Secret");
// }

int	PhoneBook::newContact(int index)
{
	std::string prompt[5] = { "First Name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "Darkest Secret: " };
	std::string field[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << prompt[i];
		getline(std::cin, field[i]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (2);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (field[i].empty())
		{
			std::cout <<  "Contact Not Added: Field '" << prompt[i].substr(0, prompt[i].length() - 2) << "' is empty" << std::endl;
			return (0);
		}
	}
	for (size_t i = 0; i < field[3].length(); i++)
	{
		if (!std::isdigit(field[3].at(i)))
		{
			std::cout << "Contact Not Added: Number field must be filled with numbers only!" << std::endl;
			return (0);
		}
	}
	if (index > 7)
	{
		for (int i = 0; i < 7; i++)
			this->_contacts[i] = this->_contacts[i + 1];
		index = 7;
	}
	this->_contacts[index].addContact(field[0], field[1], field[2], field[3], field[4]);
	return (1);
}
