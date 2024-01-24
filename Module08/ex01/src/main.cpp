# include "../inc/Span.hpp"

int main(void)
{
	try {
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(7);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}