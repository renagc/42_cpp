#include "Easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T &container, int x)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), x);
	if (it != container.end())
		return (it);
	else
		throw std::out_of_range("Element not found");
}
