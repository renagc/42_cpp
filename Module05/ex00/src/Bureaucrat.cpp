#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat: Constructor Called" << std::endl;
	this->_validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
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
	std::cout << "Bureaucrat: Operator Called" << std::endl;
	this->_validateGrade(this->_grade);
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
