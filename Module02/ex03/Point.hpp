/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:02:22 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 12:46:33 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"
# include <iostream>
# include <cmath>
# include <string>

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
		
	public:
		Point();
		Point(Fixed const & x, Fixed const & y);
		Point(Point const &other);
		~Point();

		Point &operator=(const Point &other);
		float getXvalue( void ) const;
		float getYvalue( void ) const;
};


#endif