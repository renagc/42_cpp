#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	this->_validateGrade(grade);
	std::cout << "Bureaucrat: Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
	*this = other;
	std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other.getGrade();
	this->_validateGrade(this->_grade);
	std::cout << "Bureaucrat: Operator Called" << std::endl;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

const int &Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    this->_validateGrade(this->_grade - 1);
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    this->_validateGrade(this->_grade + 1);
    this->_grade++;
}

void Bureaucrat::_validateGrade(int grade) const
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (os);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::signForm(Form& form) const
{
    try
	{
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
