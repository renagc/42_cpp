/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:45:43 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 19:45:44 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	(void)other; /*please change this*/
	std::cout << "WrongCat: Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor Called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "WrongCat: Operator Called" << std::endl;
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "This is wrong cat sound" << std::endl;
}
