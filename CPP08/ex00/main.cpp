#include "easyfind.hpp"
#include <sstream>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: " << av[0] << " <container> <value>" << std::endl;
		return 1;
	}

	std::istringstream	iss(av[1]);
	std::vector<int>	vez;
	int					num;

	while (iss >> num)
	{
		vez.push_back(num);
	}

	int	value = std::atoi(av[2]);

	::easyfind(vez, value);

	return 0;
}
