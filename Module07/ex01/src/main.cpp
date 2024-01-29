# include "iter.hpp"
# include "utils.hpp"

int main (void)
{
	int array[] = { 1, 2, 3, 4, 5 };
	iter(array, sizeof_array(array), print_iter);
	std::cout << std::endl;

	std::string strings[] = { "Isto", "é", "uma", "string" };
	iter(strings, sizeof_array(strings), print_iter);
	std::cout << std::endl;

	char chars[] = { 'a', 'b', 'c', 'd' };
	iter(chars, sizeof_array(chars), print_iter);
	std::cout << std::endl;

	float floats[] = { 32.1, 32.2, 0.0, 34.9873, 0.123 };
	iter(floats, sizeof_array(floats), print_iter);
	std::cout << std::endl;

	return (0);
}