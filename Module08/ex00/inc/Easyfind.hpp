#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>

class OutOfRangeException : public std::exception
{
	public:
		virtual const char* what() const throw() { return "Out of range"; };
};

template<typename T>
typename T::iterator easyfind(T &container, int x)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), x);
	if (it != container.end())
		return (it);
	else
		throw OutOfRangeException();
}

#endif
