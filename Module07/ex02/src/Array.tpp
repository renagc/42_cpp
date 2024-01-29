#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(0)
{
	// std::cout << "Array: Default Constructor Called" << std::endl;
	this->_array = new T[_size];
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	// std::cout << "Array: Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &other) : _array(new T[other.size()]), _size(other.size())
{
	for (unsigned int i = 0; i < other.size(); i++)
		this->_array[i] = other._array[i];
	*this = other;
	// std::cout << "Array: Copy Constructor Called" << std::endl;
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
	// std::cout << "Array: Destructor Called" << std::endl;
}

template<typename T>
T &Array<T>::operator[](int index)
{
	if (index < 0 || index >= static_cast<int>(this->_size))
		throw Array<T>::OutOfLimitsException();
	return (this->_array[index]);
}

template<typename T>
T &Array<T>::operator[](int index) const
{
	if (index < 0 || index >= static_cast<int>(this->_size))
		throw Array<T>::OutOfLimitsException();
	return (this->_array[index]);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete [] this->_array;
		this->_size = other.size();
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	// std::cout << "Array: Operator Called" << std::endl;
	return (*this);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
void Array<T>::print() const
{
	if (this->_size == 0)
		std::cout << "Array is empty" << std::endl;
	else
		std::cout << "Size of the array: " << this->_size << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << "Items[" << i <<"]: " << this->_array[i] << std::endl;
}

#endif
