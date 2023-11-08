/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:20:46 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/11/07 15:17:02 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_H
# define AAnimal_H

# include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &other);

		//subtype polymorphism
		virtual void makeSound( void ) const = 0;
		const std::string &getType( void ) const;
};

#endif
