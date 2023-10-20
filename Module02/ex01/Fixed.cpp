/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:34:08 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/20 13:40:08 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const value) : _value(value << _fractionalbits)
{
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(float const value) : _value(roundf((value) * (1 << _fractionalbits)))
{
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->_fractionalbits);
};

//1 << 8 same as 2^8
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->_fractionalbits));
}

int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream & os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
