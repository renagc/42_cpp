/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:58 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/08 09:50:25 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog: Constructor Called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog: Constructor Called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog: Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	this->_brain = new Brain(*other._brain);
	this->type = other.getType();
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
