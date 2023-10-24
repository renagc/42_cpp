/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:46 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 19:33:38 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	private:
		/*private atributes*/
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);

		//subtype polymorphism
		virtual void makeSound( void ) const;
		const std::string &getType( void ) const;
};

#endif
