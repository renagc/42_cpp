#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();

		Serializer &operator=(const Serializer &other);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
