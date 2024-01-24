#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(nullptr), _size(0)
{
	std::cout << "Array: Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	for(unsigned int i = 0; i < n; i++)
		_array[i] = 0;
	std::cout << "Array: Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &other) : _array(new T[other.getSize()]), _size(other.getSize())
{
	for (unsigned int i = 0; i < other.getSize(); i++)
		this->_array[i] = other._array[i];
	*this = other;
	std::cout << "Array: Copy Constructor Called" << std::endl;
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
	std::cout << "Array: Destructor Called" << std::endl;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfLimitsException();
	return (this->_array[index]);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete [] this->_array;
		this->_array = new T[other.getSize()];
		for (unsigned int i = 0; i < other.getSize(); i++)
			this->_array[i] = other._array[i];
	}
	std::cout << "Array: Operator Called" << std::endl;
	return (*this);
}

template<typename T>
unsigned int Array<T>::getSize() const
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
	if (this->_array)
	{
		switch (sizeof(this->_array[0]))
		{
		case 1:
			std::cout << "Memory of each item: char" << std::endl;
			break;
		case 4:
			std::cout << "Memory of each item: int" << std::endl;
			break;
		default:
			std::cout << "Memory of each item (empty)" << std::endl;
			break;
		}
	}
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << "Items[" << i <<"]: " << this->_array[i] << std::endl;
}

template class Array<int>;
