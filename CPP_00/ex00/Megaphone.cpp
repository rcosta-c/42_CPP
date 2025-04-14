#include <iostream>

int main(int ac, char **av)
{
	int x;
	int xx;

	xx = 0;
	x = 1;

	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while(x < ac)
	{
		while(av[x] && av[x][xx] && x < ac)
		{
			std::cout << static_cast<char>(std::toupper(av[x][xx]));
			xx++;
		}
		x++;
		xx = 0;
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}