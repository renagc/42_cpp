#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern: Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern: Copy Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern: Operator Called" << std::endl;
	return (*this);
}

AForm &Intern::makeForm(std::string const &formName, std::string const &target)
{
	AForm *(Intern::*formArray[3])(std::string const &target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::string knownNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (!formName.compare(knownNames[i]))
		{
			std::cout << "Intern creates " << knownNames[i] << std::endl;
			return (*(this->*formArray[i])(target));
		}
	}
	throw Intern::FormNotFoundException();
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
