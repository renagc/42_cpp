#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::cout << mstack.size() << std::endl;
	mstack.push(0);
	mstack.push(1);
	std::cout << mstack.size() << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	mstack.push(2);
	mstack.push(3);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}