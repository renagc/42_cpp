/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:56:41 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/18 13:12:09 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point const a(1, 1);
	Point const b(2, 5);
	Point const c(5 ,3);
	Point const p_1(3, 3);
	Point const p_2(1, 3);

	std::cout << "triangle " << "a: (" << a.getXvalue() << "," << a.getYvalue() << ")" << " | " << "b: (" << b.getXvalue() << "," << b.getYvalue() << ")" << " | " << "c: (" << c.getXvalue() << "," << c.getYvalue() << ")" << std::endl;
	std::cout << "p_1: (" << p_1.getXvalue() << "," << p_1.getYvalue() << ")" << std::endl;
	std::cout << "p_2: (" << p_2.getXvalue() << "," << p_2.getYvalue() << ")" << std::endl;
	std::cout << "Is p1 inside a triangle? - Answer: " << bsp(a, b, c, p_1) << std::endl;
	std::cout << "Is p2 inside a triangle? - Answer: " << bsp(a, b, c, p_2) << std::endl;
	return 0;
}