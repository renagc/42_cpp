#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// When use dynamic_cast on a pointer, if it fails it returns a Null ptr
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
	{
        std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p))
	{
        std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p))
	{
        std::cout << "C" << std::endl;
		return ;
	}
}

// When use dynamic_cast on a reference, if it fails a expection is thrown (std::bad_cast)
void identify(Base& p)
{
    try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (const std::exception& e)
	{
	}
    try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (const std::exception& e)
	{
	}
    try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (const std::exception& e)
	{
	}
}