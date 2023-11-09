#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <iostream>
# include "Node.hpp"

class LinkedList
{
	private:
		Node *_head;
	public:
		LinkedList();
		LinkedList(const LinkedList &other);
		~LinkedList();

		LinkedList &operator=(const LinkedList &other);

		void newList(AMateria *m);
		Node *lastList(void);
};

#endif
