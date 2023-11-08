/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:54 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/08 09:56:11 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : type("(animal type)")
{
	std::cout << "Animal: Constructor Called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal: Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.getType();
	std::cout << "Animal: Operator Called" << std::endl;
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "Every animal make sounds" << std::endl;
}

const std::string &Animal::getType( void ) const
{
	return(this->type);
}
