#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


void identify(Base& p);
void identify(Base* p);
Base* generate();

int main()
{
    Base* instance = generate();
	std::cout << "Dynamic_Cast by pointer: ";
    identify(instance);
	std::cout << "Dynamic_Cast by reference: ";
	identify(*instance);
    delete instance;
    return 0;
}