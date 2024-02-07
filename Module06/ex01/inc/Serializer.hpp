#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);

	public:
		~Serializer();
		
		static size_t serialize(Data* ptr);
		static Data* deserialize(size_t raw);
};

#endif
