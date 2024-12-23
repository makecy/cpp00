#include <iostream>

int	main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		std::string current_arg = av[i];
		for (size_t j = 0; j < current_arg.size(); ++j)
			current_arg[j] = toupper(current_arg[j]);
		std::cout << current_arg;
	}
	std::cout << std::endl;
	return (0);
}