#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern &operator=(const Intern &other);

		AForm &makeForm(std::string const &formName, std::string const &target);

		AForm *makeShrubberyCreationForm(std::string const &target);
		AForm *makeRobotomyRequestForm(std::string const &target);
		AForm *makePresidentialPardonForm(std::string const &target);
};

#endif
