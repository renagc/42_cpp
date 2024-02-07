#include "../inc/Span.hpp"

Span::Span() : N(0)
{
	// std::cout << "Span: Default Constructor Called" << std::endl;
}

Span::Span(unsigned int n) : N(n)
{
	// std::cout << "Span: Default Constructor Called" << std::endl;
}

Span::Span(const Span &other) : N(other.N)
{
	*this = other;
	// std::cout << "Span: Copy Constructor Called" << std::endl;
}

Span::~Span()
{
	// std::cout << "Span: Destructor Called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
	if (this->_v.size())
		this->_v.clear();
	this->_v = other._v;
	this->N = other.N;
	// std::cout << "Span: Operator Called" << std::endl;
	return (*this);
}

int	Span::operator[](unsigned int n) const
{
	if (n >= _v.size())
		throw FullVectorException();
	return _v[n];
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
	if (this->_v.size() == this->N)
		throw Span::FullVectorException();
	this->_v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator itb, std::vector<int>::iterator ite)
{
	if (std::distance(itb, ite) > N)
		throw FullVectorException();
	_v.insert(_v.end(), itb, ite);
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

const std::vector<int> &Span::getVector() const
{
	return(_v);
}

std::ostream & operator<<( std::ostream& os, Span& other)
{
	std::vector<int> vec = other.getVector();
	for (std::vector<int>::iterator it = vec.begin(); it != other.getVector().end(); it++)
		std::cout << *it << " ";
	return os;
}
