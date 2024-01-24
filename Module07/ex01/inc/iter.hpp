#include <iostream>

template <typename T>
void iter (T *array, size_t length, void (*f)(T const &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void print_iter (T const &value)
{
	std::cout << value << " ";
}

template <typename T, size_t size>
size_t	sizeof_array(T (&)[size])
{
	return (size);
}