#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <exception>

class PmergeMe
{
	private:
		int _k;
		int _N;

		std::vector< int > _vector;
		std::vector< int > _sortedVector;

		std::list< int > _list;
		std::list< int > _sortedList;

		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

		bool find(int) const;
	public:
		PmergeMe(int);
		~PmergeMe();

		void push(int);
		bool isSorted();
		void mergeInsertSortVector();

		template<typename T>
		void print(T container, const std::string &str)
		{
			typename T::iterator it = container.begin();
			std::cout << str;
			for (; it != container.end(); it++)
			{
				typename T::iterator check = it;
				std::cout << *it;
				if (container.size() > 10 && std::distance(container.begin(), it) == 10)
				{
					std::cout << " [...]";
					break ;
				}
				else if (++check == container.end())
					break ;
				std::cout << " ";
			}
			std::cout << std::endl;
		}

		template<typename T>
		void insertionSort(T &container)
		{
			typename T::iterator it_next = container.begin();
			it_next++;
			for (; it_next != container.end(); ++it_next)
			{
				typename T::iterator it = container.begin();
				for(; it != it_next; it++)
				{
					if (*it > *it_next)
					{
						int value = *it_next;
						container.erase(it_next);
						it_next = it;
						it_next++;
						container.insert(it, value);
						break;
					}
				}
			}
		}

		template<typename T>
		void mergeSort(T &container, T &target)
		{
			typename T::iterator it = container.begin();
			if (target.empty())
			{
				target.push_back(*it);
				it++;
			}
			
			for (; it != container.end(); it++)
			{
				typename T::iterator itt = target.begin();
				for (; itt != target.end(); itt++)
				{
					if (*it < *itt)
					{
						target.insert(itt, *it);
						break ;
					}
				}
				if (itt == target.end())
					target.push_back(*it);
			}
		}

		template<typename T>
		void merge(std::pair<T, T> &lst, T &target)
		{
			T temp;
			if (lst.first.size() <= static_cast<size_t>(_k))
			{
				insertionSort<T>(lst.first);
				mergeSort<T>(lst.first, temp);
			}
			else
			{
				std::pair<T, T> lstPair = split<T>(lst.first);
				merge(lstPair, target);
				lst.first.clear();
			}
			if (lst.second.size() <= static_cast<size_t>(_k))
			{
				insertionSort<T>(lst.second);
				mergeSort<T>(lst.second, temp);
			}
			else
			{
				std::pair<T, T> lstPair = split<T>(lst.second);
				merge(lstPair, target);
				lst.second.clear();
			}
			mergeSort<T>(temp, target);
		}

		template<typename T>
		std::pair<T, T> split(T &container)
		{
			T left;
			T right;
			typename T::iterator it = container.begin();
			for(size_t i = 0; i < container.size() / 2; i++)
			{
				left.push_back(*it);
				it++;
			}
			for(; it != container.end(); it++)
				right.push_back(*it);
			return (std::make_pair(left, right));
		}
		
		void sort();
};