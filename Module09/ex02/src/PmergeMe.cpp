#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _k(2)
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	_k = src._k;
	_vector = src._vector;
	_list = src._list;
	return (*this);
}

PmergeMe::PmergeMe(int k) : _k(k), _N(0)
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::push(int n)
{
	_list.push_back(n);
	_vector.push_back(n);
	_N++;
}

bool PmergeMe::find(int n) const
{
	std::list<int>::const_iterator it = _list.begin();
	for (; it != _list.end(); it++)
		if (n == (*it))
			return (true);
	return (false);
}

bool PmergeMe::isSorted()
{
	std::list<int>::iterator it = _list.begin();
	std::list<int>::iterator it_temp = _list.begin();
	for (; it != _list.end(); it++)
	{
		if (++it_temp != _list.end() && *it > *it_temp)
			return (false);
	}
	return (true);
}

void PmergeMe::sort()
{
	{
		clock_t start = clock();
		std::pair<std::vector<int>,std::vector<int> > vectorPair = split<std::vector<int> >(_vector);
		print<std::vector<int> >(_vector, "Before: ");
		merge<std::vector<int> >(vectorPair, _sortedVector);
		print<std::vector<int> >(_sortedVector, "After: ");
		std::cout << "time executing Sort Vector: " << static_cast<float>(clock() - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	}
	{
		clock_t start = clock();
		std::pair<std::list<int>,std::list<int> > lstPair = split<std::list<int> >(_list);
		merge<std::list<int> >(lstPair, _sortedList);
		std::cout << "time executing Sort List: " << static_cast<float>(clock() - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
	}
}
