#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <string>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: Out of limits");
				}
		};
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		Array &operator=(const Array &other);
		T &operator[](int index);
		T &operator[](int index) const;

		unsigned int size() const;
		void print() const;
};

# include "../src/Array.tpp"

#endif
