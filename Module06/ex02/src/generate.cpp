#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ctime"
#include "cstdlib"

Base* generate()
{
	// Get current time
	time_t now = std::time(0);
	// Seed random number generator
    std::srand(static_cast<unsigned>(now));

    int choice = std::rand() % 3;

    switch (choice) {
        case 0:
            return new A();
			break;
        case 1:
            return new B();
			break;
        default:
            return new C();
			break;
    }
}