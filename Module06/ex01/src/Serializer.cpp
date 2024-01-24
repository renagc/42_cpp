#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer: Default Constructor Called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
	std::cout << "Serializer: Copy Constructor Called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer: Destructor Called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	std::cout << "Serializer: Operator Called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}