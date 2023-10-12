/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:55:21 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 10:35:35 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	prompt;
	int			index;
	int			suc;

	index = 0;
	while (1)
	{
		if (!std::cin.eof())
			std::cout << "Choose ADD, SEARCH or EXIT: ";
		getline(std::cin, prompt);
		if (std::cin.eof() || !prompt.compare("EXIT"))
		{
			std::cout << std::endl;
			return (0);
		}
		else if (!prompt.compare("ADD"))
		{
			suc = book.newContact(index);
			if (suc == 1 && index < 8)
				index++;
			else if (suc == 2)
				return (0);
		}
		else if (!prompt.compare("SEARCH"))
		{
			book.searchContact(index);
			if (std::cin.eof())
				return (0);
		}
	}
	return (0);
}