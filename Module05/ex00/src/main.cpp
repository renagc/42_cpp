#include "Bureaucrat.hpp"

void increment(Bureaucrat &bureaucrat)
{
    try
    {
        std::cout << "before incerement:" << std::endl;
        std::cout << "  " << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << "after increment:"<< std::endl;
        std::cout << "  " << bureaucrat << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void decrement(Bureaucrat &bureaucrat)
{
    try
    {
        std::cout << "before decerement:" << std::endl;
        std::cout << "  " << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << "after decrement:"<< std::endl;
        std::cout << "  " << bureaucrat << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    {
        Bureaucrat bureaucrat("A", 50);
        increment(bureaucrat);
        decrement(bureaucrat);
    }
    {
        Bureaucrat bureaucrat("B", 1);
        increment(bureaucrat);
        decrement(bureaucrat);
    }
    {
        Bureaucrat bureaucrat("C", 150);
        decrement(bureaucrat);
        increment(bureaucrat);
    }
    try
    {
        Bureaucrat bureaucrat("D", 0);
        bureaucrat.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat("D", 151);
        bureaucrat.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return (0);
}