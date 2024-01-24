#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm: Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)  : AForm("RobotomyRequestForm", 72, 45)
{
	*this = other;
	std::cout << "RobotomyRequestForm: Copy Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor Called" << std::endl;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other.getTarget();
	std::cout << "RobotomyRequestForm: Operator Called" << std::endl;
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::validateGrade(executor.getGrade());
    if (!this->getSigned())
        throw AForm::GradeNotSignedException();
	std::cout << "Brr" << std::endl;
	std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
}

