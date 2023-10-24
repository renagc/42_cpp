/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:51 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 17:50:37 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);
		virtual void makeSound( void ) const;
};

#endif
