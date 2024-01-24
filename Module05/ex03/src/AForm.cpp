#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm: Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm: Constructor Called" << std::endl;
	this->validateGrade(this->_gradeToSign);
	this->validateGrade(this->_gradeToExecute);
}

AForm::AForm(const AForm &other) : _name("copy"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	*this = other;
	std::cout << "AForm: Copy Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm: Destructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	this->_signed = other.getSigned();
	std::cout << "AForm: Operator Called" << std::endl;
	return (*this);
}

const std::string &AForm::getName() const
{
	return (this->_name);
}

const int &AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

const int &AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

const bool &AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::validateGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << ", Signed: " << (form.getSigned() ? "Yes" : "No");
    return (os);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char*	AForm::GradeNotSignedException::what() const throw()
{
	return ("Grade not signed");
}

