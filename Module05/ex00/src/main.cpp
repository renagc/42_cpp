#include "Bureaucrat.hpp"

int main()
{
	try {
        Bureaucrat bureaucrat1("John Doe", 50);
        std::cout << bureaucrat1 << std::endl;
		bureaucrat1.incrementGrade();
		Bureaucrat bureaucrat2("John Doe", 1);
		bureaucrat2.incrementGrade();
        std::cout << bureaucrat2 << std::endl;
		Bureaucrat bureaucrat3("John Doe", 150);
		bureaucrat3.decrementGrade();
        std::cout << bureaucrat3 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return (0);
}