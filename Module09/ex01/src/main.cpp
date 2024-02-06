#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		RPN rpn;
		if (ac != 2)
			throw RPN::InvalidArguments();
		(void)av;
		rpn.calculate(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}