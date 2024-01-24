#ifndef A_H
# define A_H

# include <iostream>
# include "Base.hpp"

class A : public Base
{
	public:
		A();
		A(const A &other);
		~A();

		A &operator=(const A &other);
};

#endif
