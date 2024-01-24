#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	time_t now = std::time(0);
    std::srand(static_cast<unsigned>(now));

    int choice = std::rand() % 3;

    switch (choice) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}