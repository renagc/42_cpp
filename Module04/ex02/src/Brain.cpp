/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:13:43 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/08 10:08:56 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain: Copy Constructor Called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
	return (*this);
}

void Brain::setIdeas( std::string ideas[100] )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
}

const std::string *Brain::getIdeas( void ) const
{
	return (this->_ideas);
}

