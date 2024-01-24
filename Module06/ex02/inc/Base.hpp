#ifndef BASE_H
# define BASE_H

# include <iostream>

class Base
{
	public:
		Base();
		Base(const Base &other);
		virtual ~Base();

		Base &operator=(const Base &other);
};

#endif
