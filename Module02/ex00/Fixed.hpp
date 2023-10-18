/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:26:29 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/17 12:52:52 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed &operator=(const Fixed &other);

	private:
		int	_value;
		static int const _fractionalbits = 8;
};

#endif
