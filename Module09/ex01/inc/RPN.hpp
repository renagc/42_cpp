#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN &);
		RPN &operator=(const RPN &);
		~RPN();

		class InvalidArguments : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class CantDoMath : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class StackSize : public std::exception
		{
			public:
				virtual const char *what() const throw() {return ("Error");}
		};
		class CantDivide : public std::exception
		{
			public:
				virtual const char *what() const throw() {return ("Cant divide by 0");}
		};
		class OutOfLimits : public std::exception
		{
			public:
				virtual const char *what() const throw() {return ("Out of limits");}
		};
		void reverse();
	
		void calculate(const std::string &);
		void doOperation(char);
		size_t pushValue(const std::string &);

		void checkArgument(const std::string &);

		bool istoken(char);
};

#endif