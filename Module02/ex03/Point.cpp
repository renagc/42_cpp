/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:02:17 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 13:02:42 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
	//std::cout << "Constructor Called" << std::endl;
}

Point::Point(Fixed const & x, Fixed const & y) : _x(x.getRawBits()), _y(y.getRawBits())
{
	//std::cout << "Constructor Called" << std::endl;
}

Point::~Point()
{
	//std::cout << "Destructor Called" << std::endl;
}

Point &Point::operator=(const Point &other)
{
	(Fixed &)this->_x = other._x;
	(Fixed &)this->_y = other._y;
	return (*this);
}

Point::Point(Point const &other)
{
	//std::cout << "Constructor Called" << std::endl;
	*this = other;
}

float Point::getXvalue( void ) const
{
	return this->_x.toFloat();
}

float Point::getYvalue( void ) const
{
	return this->_y.toFloat();
}
