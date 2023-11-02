#ifndef OLA_H
# define OLA_H

# include <iostream>

class Ola
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		Ola();
		Ola(const Ola &other);
		~Ola();

		Ola &operator=(const Ola &other);
};

#endif
