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
		int N = 10;
		Span sp = Span(N);
		std::vector<double> example;
		std::vector<double>::iterator it;
		std::vector<double> example2;
		std::vector<double>::iterator it2;

		example2.push_back(-9);
		example2.push_back(-10);
		for (size_t i = 0; i < 5; i++)
			example.push_back((i + 1) * 3);
		for (size_t i = 0; i < static_cast<size_t>(N / 2); i++)
			sp.addNumber(i * 10);
		it = example.begin();
		sp.addNumber(example.begin(), example.end());

		//print span vector
		for (size_t i = 0; i < sp.getVector().size(); i++)
			std::cout << "span_vector[" << i << "]: " << sp.getVector().at(i) << std::endl;
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