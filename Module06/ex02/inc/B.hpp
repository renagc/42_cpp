#ifndef B_H
# define B_H

# include <iostream>
# include "Base.hpp"

class B : public Base
{
	public:
		B();
		B(const B &other);
		~B();

		B &operator=(const B &other);
};

#endif
