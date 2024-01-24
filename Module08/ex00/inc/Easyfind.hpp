#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int x);

# include "../src/easyfind.tpp"

#endif
