#ifndef CURE_H
# define CURE_H

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		Cure();
		Cure(const Cure &other);
		~Cure();

		Cure &operator=(const Cure &other);

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif
