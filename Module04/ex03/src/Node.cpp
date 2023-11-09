#include "../inc/Node.hpp"

Node::Node() : _m(NULL), _next(NULL)
{
	std::cout << "Node: Default Constructor Called" << std::endl;
}

Node::Node(AMateria &m) : _m(&m), _next(NULL)
{
	std::cout << "Node: AMateria Constructor Called" << std::endl;
}

Node::Node(const Node &other)
{
	*this = other;
	std::cout << "Node: Copy Constructor Called" << std::endl;
}

Node::~Node()
{
	std::cout << "Node: Destructor Called" << std::endl;
}

Node &Node::operator=(const Node &other)
{
	delete this->_m;
	this->_m = other.getMateria()->clone();
	this->_next = other.getPointer();
	std::cout << "Node: Operator Called" << std::endl;
	return (*this);
}

void Node::setMateria(AMateria *m)
{
	this->_m = m;
}

AMateria *Node::getMateria(void) const
{
	return (this->_m);
}

void Node::setPointer(Node *node)
{
	this->_next = node;
}

Node *Node::getPointer(void) const
{
	return (this->_next);
}

