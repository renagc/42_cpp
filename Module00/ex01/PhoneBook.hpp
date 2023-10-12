/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:38:07 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 10:29:55 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>
# include <string>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int		newContact(int index);
		void	searchContact(int index);
		void	fillList(void);
		
	private:
		Contact _contacts[8];
};

#endif