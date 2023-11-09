#include "../inc/LinkedList.hpp"

LinkedList::LinkedList() : _head(NULL)
{
	std::cout << "LinkedList: Default Constructor Called" << std::endl;
}

LinkedList::LinkedList(const LinkedList &other)
{
	*this = other;
	std::cout << "LinkedList: Copy Constructor Called" << std::endl;
}

LinkedList::~LinkedList()
{
	Node *temp;
	Node *next;

	temp = this->_head;
	while(temp)
	{
		next = temp->getPointer();
		delete temp;
		temp = next;
	}
	std::cout << "LinkedList: Destructor Called" << std::endl;
}

LinkedList &LinkedList::operator=(const LinkedList &other)
{
	Node *temp = this->_head;
	Node *next;
	while (temp)
	{
		next = temp->getPointer();
		delete temp;
		temp = next;
	}

	Node *temp2 = other._head;
	Node **curr = &this->_head;
	Node *next2;

	while (temp2)
	{
		*curr = new Node(*temp2->getMateria());
		temp2 = temp2->getPointer();
		next2 = (*curr)->getPointer();
		curr = &next2;
	}
	std::cout << "LinkedList: Operator Called" << std::endl;
	return (*this);
}

void LinkedList::newList(AMateria *m)
{
	Node *temp = new Node(*m);

	if (!this->_head)
		this->_head = temp;
	else
	{
		Node *temp2 = this->lastList();
		temp2->setPointer(temp);
	}
}

Node *LinkedList::lastList(void)
{
	Node *temp;

	temp = this->_head;
	while (temp->getPointer())
		temp = temp->getPointer();
	return (temp);
}

