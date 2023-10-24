/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:45:41 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 19:53:18 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("(undefined wrong animal)")
{
	std::cout << "WrongAnimal: Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	(void)other; /*please change this*/
	std::cout << "WrongAnimal: Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "WrongAnimal: Operator Called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "Every animal make sounds" << std::endl;
}

const std::string &WrongAnimal::getType( void ) const
{
	return (this->type);
}
