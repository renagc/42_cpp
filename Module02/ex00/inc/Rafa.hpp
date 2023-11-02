#ifndef RAFA_H
# define RAFA_H

# include <iostream>

class Rafa
{
	private:
		/*private atributes*/
	protected:
		/*protected atributes*/
	public:
		Rafa();
		Rafa(const Rafa &other);
		~Rafa();

		Rafa &operator=(const Rafa &other);
};

#endif
