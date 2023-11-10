#include "Harl.hpp"

int	main()
{
	std::string	level;
	Harl		harl;

	std::cout << BLUE "Harl 2.0" CLR_RMV << std::endl;
	while (42)
	{
		std::cout << BLUE "> " CLR_RMV << std::flush;
		std::getline(std::cin, level);
		if (level == "q")
			return 0;
		else if (!level.empty())
			harl.complain(level);
	}
	return 0;
}
