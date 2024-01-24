#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form: Default Constructor Called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_validateGrade(this->_gradeToSign);
	this->_validateGrade(this->_gradeToExecute);
	std::cout << "Form: Constructor Called" << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()), _signed(other.getSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
	*this = other;
	std::cout << "Form: Copy Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form: Destructor Called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	this->_signed = other.getSigned();
	std::cout << "Form: Operator Called" << std::endl;
	return (*this);
}

const std::string &Form::getName() const
{
	return (this->_name);
}

const int &Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

const int &Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

const bool &Form::getSigned() const
{
	return (this->_signed);
}

void Form::_validateGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << ", Signed: " << (form.getSigned() ? "Yes" : "No");
    return (os);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

