/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:54 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/08 09:56:11 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : type("(AAnimal type)")
{
	std::cout << "AAnimal: Constructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << "AAnimal: Constructor Called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor Called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	this->type = other.getType();
	std::cout << "AAnimal: Operator Called" << std::endl;
	return (*this);
}

const std::string &AAnimal::getType( void ) const
{
	return(this->type);
}
