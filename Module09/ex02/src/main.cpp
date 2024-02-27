#include "PmergeMe.hpp"
#include <cstring>
#include <cctype>
#include <climits>

// Small number of elements:
//		vector: Dynamic memory allocation might be relatively more expensive for small sizes
//		list: Efficient insertion and deletion at any position, even in the middle.
// Large number of elements:
//		vector: Efficient random access, cache-friendly due to contiguous memory, faster iteration.
//		list: Slower iteration, higher memory overhead.

int main(int ac, char **av)
{
	try
	{
		if (ac < 3)
			throw std::invalid_argument("Usage Ex: ./PmergeMe 5 2 3 1 4");
		PmergeMe Algorithm(2);
		for (int i = 1; i < ac; i++)
		{
			for (size_t j = 0; j < std::strlen(av[i]); j++)
				if (!std::isdigit(av[i][j]))
					throw std::invalid_argument("Some arguments not numbers");
			long int value = std::atof(av[i]);
			if (value > std::numeric_limits<int>::max())
				throw std::invalid_argument("Some numbers bigger than max int");
			Algorithm.push(value);
		}
		if (Algorithm.isSorted())
			throw std::invalid_argument("Already Sorted");
		Algorithm.sort();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}