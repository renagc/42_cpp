#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include <limits>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int N;
	public:
		class FullVectorException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &other);
		int operator[](unsigned int n) const;

		void addNumber(int n);
		void addNumber(int low, int high);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		const std::vector<int> &getVector() const;
};

std::ostream & operator<<( std::ostream& os, Span& other );

#endif
