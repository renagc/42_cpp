#ifndef ICE_H
# define ICE_H

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();

		Ice &operator=(const Ice &other);

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif
