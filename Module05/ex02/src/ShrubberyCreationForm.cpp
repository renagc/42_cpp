#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm: Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm: Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)  : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
	std::cout << "ShrubberyCreationForm: Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor Called" << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other.getTarget();
	std::cout << "ShrubberyCreationForm: Operator Called" << std::endl;
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::validateGrade(executor.getGrade());
    if (!this->getSigned())
        throw AForm::GradeNotSignedException();
	std::ofstream outfile(this->_target + "_shrubbery", std::ofstream::trunc);
	if (!outfile.is_open())
		throw std::runtime_error("Cannot open file");
	outfile << "   ^   \n";
    outfile << "  ^^^  \n";
    outfile << " ^^^^^ \n";
    outfile << "^^^^^^^\n";
}

