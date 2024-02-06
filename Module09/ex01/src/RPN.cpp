#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	this->_stack = src._stack;
	return (*this);
}

RPN::~RPN() {}

const char * RPN::InvalidArguments::what() const throw()
{
	return ("Invalid Arguments (usage: ./RPN '3 4 + (...)')");
}

const char * RPN::CantDoMath::what() const throw()
{
	return ("Cant calculate");
}

void RPN::calculate(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (std::isspace(str.at(i)))
			continue;
		else if (std::isdigit(str.at(i)))
			i += pushValue(str.substr(i, str.size() - i));
		else if (istoken(str.at(i)))
		{
			if (i + 1 < str.size() && std::isdigit(str.at(i + 1)) \
				&& str.at(i) != '*' && str.at(i) != '/')
				i += pushValue(str.substr(i, str.size() - i));
			else if ((i + 1 < str.size() && !std::isspace(str.at(i + 1))) \
				|| _stack.empty())
				throw CantDoMath();
			else
				doOperation(str.at(i));
		}
		else
			throw CantDoMath();
	}
	if (_stack.size() != 1)
		throw StackSize();
	std::cout << _stack.top() << std::endl;
}

void RPN::doOperation(char c)
{
	if (_stack.size() == 1)
		throw StackSize();
	this->reverse();
	long int value = _stack.top();
	_stack.pop();
	while(!_stack.empty())
	{
		if (c == '+')
			value += _stack.top();
		else if (c == '-')
			value -= _stack.top();
		else if (c == '*')
			value *= _stack.top();
		else if (c == '/')
		{
			if (_stack.top() == 0)
				throw CantDivide();
			value /= _stack.top();
		}
		_stack.pop();
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw OutOfLimits();
	}
	_stack.push(value);
}

void RPN::reverse()
{
	std::stack<int> temp;

	if (_stack.empty())
		return ;
	while (!_stack.empty())
	{
		temp.push(_stack.top());
		_stack.pop();
	}
	_stack.swap(temp);
}

size_t RPN::pushValue(const std::string &str)
{
	int start = 0;
	size_t end = 0;
	while (end + 1 < str.size() && std::isdigit(str.at(end + 1)))
		end++;
	long int value = std::atol(str.substr(start, end - start + 1).c_str());
	_stack.push(value);
	if (end + 1 < str.size() && !std::isspace(str.at(end + 1)))
		throw StackSize();
	return (end - start);
}

bool RPN::istoken(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}
