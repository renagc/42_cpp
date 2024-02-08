#include "easyfind.hpp"

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
	try
	{
		std::vector<int>::iterator it = easyfind(v, 50);
		std::cout << "Element found pos: " << std::distance(v.begin(), it) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator it = easyfind(v, 0);
		std::cout << "Element found pos: " << std::distance(v.begin(), it) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::string str = "renaton";
		std::string::iterator it = easyfind(str, 'n');
		std::cout << "Element found pos: " << std::distance(str.begin(), it) << std::endl;
		std::string::iterator it2 = easyfind(str, 'z');
		std::cout << "Element found pos: " << std::distance(str.begin(), it2) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}