/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:45:38 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/24 19:46:03 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();

		WrongCat &operator=(const WrongCat &other);
		void makeSound( void ) const;
};

#endif
