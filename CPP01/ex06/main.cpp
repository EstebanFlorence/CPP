#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong arguments" << std::endl;
		std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}

	int			level = -1;
	std::string	log = av[1];
	Harl		harl;
	if (log == "DEBUG")
		level = 0;
	else if (log == "INFO")
		level = 1;
	else if (log == "WARNING")
		level = 2;
	else if (log == "ERROR")
		level = 3;
	harl.complain(level);

	return 0;
}
