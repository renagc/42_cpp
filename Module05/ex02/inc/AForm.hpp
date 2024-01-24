#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		class GradeNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExecute() const;
		const bool &getSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void validateGrade(int grade) const;
		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
