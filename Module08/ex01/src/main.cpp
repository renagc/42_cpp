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
	try {
		Span sp = Span(5);
		std::vector<int> sp_copy;
		std::vector<int> ok(50);

		for (size_t i = 0; i < sp_copy.size(); i++)
			ok.at(i) = i * 10;

		for (size_t i = 0; i < sp_copy.size(); i++)
			std::cout << sp_copy[i] << ", ";
		std::cout << std::endl;
		std::cout << "Filled (longest): " << sp.longestSpan() << std::endl;
		std::cout << "Filled (shortest): " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}