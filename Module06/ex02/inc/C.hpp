#ifndef C_H
# define C_H

# include <iostream>
# include "Base.hpp"

class C : public Base
{
	public:
		C();
		C(const C &other);
		~C();

		C &operator=(const C &other);
};

#endif
