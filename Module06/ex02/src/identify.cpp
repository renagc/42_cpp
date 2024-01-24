#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
	else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    identify(&p);
}