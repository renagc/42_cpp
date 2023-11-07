#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain: Copy Constructor Called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
	return (*this);
}

