/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:25:49 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 12:55:40 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float const det_pc = point.getXvalue() * c.getYvalue() - point.getYvalue() * c.getXvalue();
	float const det_ac = a.getXvalue() * c.getYvalue() - a.getYvalue() * c.getXvalue();
	float const det_bc = b.getXvalue() * c.getYvalue() - b.getYvalue() * c.getXvalue();
	float const det_pb = point.getXvalue() * b.getYvalue() - point.getYvalue() * b.getXvalue();
	float const det_ab = a.getXvalue() * b.getYvalue() - a.getYvalue() * b.getXvalue();
	float result_a;
	float result_b;
	
	result_a = (float)((det_pc - det_ac) / det_bc);
	result_b = -(float)((det_pb - det_ab) / det_bc);
	if (result_a > 0 && result_a < 1 && result_b > 0 && result_b < 1)
		return (true);
	else
		return (false);
}