/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 19:23:39 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog: Constructor Called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
    this->_brain = new Brain(other.getBrain());
	std::cout << "Dog: Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	std::cout << "Dog: Operator Called" << std::endl;
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "bark" << std::endl;
}

Brain &Dog::getBrain( void ) const
{
    return (*this->_brain);
}


