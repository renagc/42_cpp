#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
		void _validateGrade(int grade) const;

	public:
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &other);

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExecute() const;
		const bool &getSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
