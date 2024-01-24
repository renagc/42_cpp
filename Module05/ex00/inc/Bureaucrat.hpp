#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
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
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string &getName() const;
		const int &getGrade() const;

		void incrementGrade();
		void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
