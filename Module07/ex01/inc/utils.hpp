#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

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

#endif