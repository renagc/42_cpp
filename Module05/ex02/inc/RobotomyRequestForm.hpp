#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		
		virtual void execute(const Bureaucrat& executor) const;

		const std::string &getTarget() const;
};

#endif
