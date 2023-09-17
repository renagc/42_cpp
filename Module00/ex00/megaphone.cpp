//#include <string>
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
				if (av[i][j] <= 'z' && av[i][j] >= 'a')
					av[i][j] -= 32;
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
}