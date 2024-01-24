#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		AForm *form;

        form = &intern.makeForm("shrubbery creation", "A");
		std::cout << (*form).getName() << std::endl;
		std::cout << (*static_cast<ShrubberyCreationForm *>(form)).getTarget() << std::endl;
		delete form;
        form = &intern.makeForm("robotomy request", "B");
		delete form;
        form = &intern.makeForm("presidential pardon", "C");
		delete form;
        form = &intern.makeForm("whatever", "D");
		delete form;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}