#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
        Bureaucrat bureaucrat("John Doe", 50);

        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Target");
        PresidentialPardonForm pardonForm("Subject");

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);

        shrubberyForm.beSigned(bureaucrat);
        robotomyForm.beSigned(bureaucrat);
        pardonForm.beSigned(bureaucrat);

        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);

    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}