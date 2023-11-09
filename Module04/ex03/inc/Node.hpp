#ifndef NODE_H
# define NODE_H

# include <iostream>
# include "AMateria.hpp"

class Node
{
	private:
		AMateria *_m;
		Node	*_next;
	public:
		Node();
		Node(AMateria &m);
		Node(const Node &other);
		~Node();

		Node &operator=(const Node &other);

		void setMateria(AMateria *m);
		AMateria *getMateria(void) const;
		void setPointer(Node *node);
		Node *getPointer(void) const;
};

#endif
