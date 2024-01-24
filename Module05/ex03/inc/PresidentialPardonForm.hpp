#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		
		virtual void execute(const Bureaucrat& executor) const;

		const std::string &getTarget() const;
};

#endif
