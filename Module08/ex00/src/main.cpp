#include "Easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Element found pos: " << std::distance(v.begin(), it) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}