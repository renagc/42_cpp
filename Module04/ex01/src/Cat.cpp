/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:56 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 19:23:25 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->_brain = new Brain;
	this->type = "Cat";
	std::cout << "Cat: Constructor Called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << "Cat: Constructor Called" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
	std::cout << "Cat: Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.getType();
    this->_brain = new Brain(other.getBrain());
	std::cout << "Cat: Operator Called" << std::endl;
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "meow" << std::endl;
}

Brain &Cat::getBrain( void ) const
{
    return (*this->_brain);
}

