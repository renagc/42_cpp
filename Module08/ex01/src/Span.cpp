#include "../inc/Span.hpp"

Span::Span() : _n(0)
{
	std::cout << "Span: Default Constructor Called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Span: Default Constructor Called" << std::endl;
}

Span::Span(const Span &other) : _n(other._n)
{
	this->_v = other._v;
	*this = other;
	std::cout << "Span: Copy Constructor Called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span: Destructor Called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_v = other._v;
		this->_n = other._n;
	}
	std::cout << "Span: Operator Called" << std::endl;
	return (*this);
}

const char *Span::FullVectorException::what() const throw()
{
	return ("Span: List is full");
}

const char *Span::NoSpanFoundException::what() const throw()
{
	return ("Span: Span not found");
}

void Span::addNumber(int n)
{
	if (this->_v.size() == this->_n)
		throw Span::FullVectorException();
	this->_v.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw NoSpanFoundException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	int spanMin = std::numeric_limits<int>::max();
	for (size_t i = 0; i < (v.size() - 1); i++)
	{
		int span = v[i + 1] - v[i];
		if (span < spanMin)
			spanMin = span;
	}
	return (spanMin);
}

unsigned int Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw NoSpanFoundException();
	std::vector<int>::iterator its = std::min_element(this->_v.begin(), this->_v.end());
	std::vector<int>::iterator ite = std::max_element(this->_v.begin(), this->_v.end());
	return (*ite - *its);
}
