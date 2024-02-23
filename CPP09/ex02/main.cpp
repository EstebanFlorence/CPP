#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <input sequence>" << std::endl;
		return 1;
	}

	std::string	input;

	for (int i = 1; i < ac; i++)
	{
		input += av[i];
		if (i < ac - 1)
			input += " ";
	}

	try
	{
		PmergeMe	sorter(input);

		sorter.run();
		std::cout << sorter << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}



	return 0;
}
