#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &other);

		AMateria* createMateria(std::string const & type);
		void learnMateria(AMateria*);
};

#endif
