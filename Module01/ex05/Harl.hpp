/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:54:09 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/12 18:31:09 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

class Harl
{
private:
	void _debug( void );
    void _info( void );
    void _warning( void );
    void _error( void );
	std::string	_lvls[4];
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif