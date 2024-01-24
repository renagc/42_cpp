#include "../inc/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack: Default Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	*this = other;
	std::cout << "MutantStack: Copy Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack: Destructor Called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	(void)other; /*change this to be like this->setPrivate(other->getPrivate())*/
	std::cout << "MutantStack: Operator Called" << std::endl;
	return (*this);
}

template <typename T>
typename  MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename  MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename  MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename  MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename  MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename  MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename  MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}

template class MutantStack<int>;

