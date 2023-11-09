/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:51 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/07 16:17:07 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	private:
		Brain * _brain;
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);
		void makeSound( void ) const;
		Brain &getBrain( void ) const;
};

#endif
