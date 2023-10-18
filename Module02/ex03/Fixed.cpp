/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:34:08 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 12:23:28 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const value) : _value(value << _fractionalbits)
{
	//std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(float const value) : _value(roundf((value) * (1 << _fractionalbits)))
{
	//std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
};

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractionalbits);
};

//1 << 8 same as 2^8
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fractionalbits));
}

int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

std::ostream &operator<<(std::ostream & os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

//comparison
Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assigment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}


//arithmetic
Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int n)
{
	(void)n;
	Fixed temp(this->toFloat());
	this->_value++;
	return (temp);
}

Fixed Fixed::operator--(int n)
{
	(void)n;
	Fixed temp(this->toFloat());
	this->_value--;
	return (temp);
}

Fixed &Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
