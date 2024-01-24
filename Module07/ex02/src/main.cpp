#include "Array.tpp"

int main(void)
{
	try {
		Array<int> a(5);
		a.print();
		a[6];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}