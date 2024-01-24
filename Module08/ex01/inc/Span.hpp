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
		unsigned int _n;
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

		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		unsigned int getN() const;
};

#endif
