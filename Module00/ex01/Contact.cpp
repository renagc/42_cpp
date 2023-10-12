/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:40:52 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 09:52:05 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor Called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Destructor Called" << std::endl;
}

void Contact::addContact(std::string first, std::string last, std::string nick, std::string number, std::string secret)
{
	this->_first_name = first;
	this->_last_name = last;
	this->_nickname = nick;
	this->_phone_number = number;
	this->_darkest_secret = secret;
}

void Contact::displayPrivate(void)
{
	std::string	first;
	std::string last;
	std::string nick;

	first = this->_first_name.substr(0, 9);
	last = this->_last_name.substr(0, 9);
	nick = this->_nickname.substr(0, 9);

	if (this->_first_name.length() > 9)
		first += ".";
	if (this->_last_name.length() > 9)
		last += ".";
	if (this->_nickname.length() > 9)
		nick += ".";
	std::cout << std::right << std::setw(10) << first << " | ";
	std::cout << std::right << std::setw(10) << last << " | ";
	std::cout << std::right << std::setw(10) << nick << std::endl;
}

void Contact::showPrivate(void)
{
	std::cout << "First Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
}
