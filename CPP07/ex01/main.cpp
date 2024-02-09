#include "iter.hpp"

int	main()
{
	int		a[] = {1, 2, 3, 4, 5};
	double	b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	const char*	c[] = {"Diego", "Armando", "Maradona"};

	std::cout << "Integer array:" << std::endl;
	::iter(a, sizeof(a) / sizeof(a[0]),  printType<int>);
	std::cout << std::endl;
	::iter(a, sizeof(a) / sizeof(a[0]),  power<int>);
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "Double array:" << std::endl;
	::iter(b, sizeof(b) / sizeof(b[0]),  printType<double>);
	std::cout << std::endl;
	::iter(b, sizeof(b) / sizeof(b[0]),  power<double>);
	for (size_t i = 0; i < sizeof(b) / sizeof(b[0]); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	std::cout << "String array:" << std::endl;
	::iter(c, sizeof(c) / sizeof(c[0]), printType<const char*>);
	std::cout << std::endl;

	return 0;
}
