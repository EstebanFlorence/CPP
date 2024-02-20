#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
		return 1;
	}

	// try
	// {
	// 	// RPN	rpn2(av[1]);
	// 	// ...
	// 	rpn.setExpression(av[1]);
	// }
	// catch(const std::exception& ex)
	// {
	// 	std::cerr << ex.what() << std::endl;
	// 	return 1;
	// }

	RPN	rpn(av[1]);

	std::cout << av[1] << std::endl;
	if (rpn.evaluateRPN())
		std::cout << rpn.getResult() << std::endl;

	return 0;
}
