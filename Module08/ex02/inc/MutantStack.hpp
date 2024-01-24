#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>
# include <deque>
# include <list>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();

		MutantStack &operator=(const MutantStack &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_iterator begin() const;
		const_iterator end() const;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

# include "../src/MutantStack.tpp"

#endif
