/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:45:49 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/07 16:14:27 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAAnimal_H
# define WRONGAAnimal_H

# include <iostream>

class WrongAAnimal
{
	protected:
		std::string type;
	public:
		WrongAAnimal();
		WrongAAnimal(const WrongAAnimal &other);
		~WrongAAnimal();

		WrongAAnimal &operator=(const WrongAAnimal &other);

		void makeSound( void ) const;
		const std::string &getType( void ) const;
};

#endif
