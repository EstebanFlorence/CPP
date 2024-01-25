#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
		return 1;
	}
	ScalarConerter::convert(av[1]);

	return 0;
}
