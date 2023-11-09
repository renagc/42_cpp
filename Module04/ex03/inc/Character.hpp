#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "AMateria.hpp"
# include "LinkedList.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_m[4];
		LinkedList	*list;
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		~Character();

		Character &operator=(const Character &other);

		std::string const & getName( void ) const;
		virtual void equip(AMateria* m);
		virtual void use(int idx, ICharacter& target);
		virtual void unequip(int idx);
};

#endif
