/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:56 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/07 15:12:26 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat: Constructor Called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat: Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.getType();
	std::cout << "Cat: Operator Called" << std::endl;
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "meow" << std::endl;
}

