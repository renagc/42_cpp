/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:56 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/08 10:00:18 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain();
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
	delete _brain;
	std::cout << "Cat: Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->_brain = new Brain(*other._brain);
	this->type = other.getType();
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

