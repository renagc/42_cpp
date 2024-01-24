#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm: Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm: Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)  : AForm("PresidentialPardonForm", 25, 5)
{
	*this = other;
	std::cout << "PresidentialPardonForm: Copy Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor Called" << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->_target = other.getTarget();
	std::cout << "PresidentialPardonForm: Operator Called" << std::endl;
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::validateGrade(executor.getGrade());
    if (!this->getSigned())
        throw AForm::GradeNotSignedException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

