#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
        Bureaucrat bureaucrat1("John Doe", 29);
		Bureaucrat bureaucrat2("Mike Doe", 40);
        Form form("Tax Form", 30, 40);
        std::cout << form << std::endl;
        bureaucrat1.signForm(form);
        std::cout << form << std::endl;
		// bureaucrat2.signForm(form);
        Form invalidForm("Invalid Form", 160, 170);
    }
    catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return (0);
}