#include "BitcoinExchange.hpp"

int	checkInnit(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
		return 1;
	}

	std::ifstream	databaseFile("./data.csv");
	std::ifstream	inputFile(av[1]);

	if (!databaseFile)
	{
		std::cerr << "Error: missing database file" << std::endl;
		return 1;
	}
	else if (!inputFile)
	{
		std::cerr << "Error: missing input file" << std::endl;
		return 1;
	}

	databaseFile.close();
	inputFile.close();

	return 0;
}

int	main(int ac, char **av)
{
	if (checkInnit(ac, av))
		return 1;

	BitcoinExchange	bit(av[1]);

	if (!bit.parseDatabase())
		return 1;
	if (bit.parseInputFile())
		return 1;

	return 0;
}
