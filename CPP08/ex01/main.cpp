#include "Span.hpp"
#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	Span sp1 = Span(5);

	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	if (ac != 2 || !std::strtol(av[1], NULL, 10))
	{
		std::cout << "Usage: " << av[0] << " <size>" << std::endl;
		return 1;
	}

	Span				sp2 = Span(std::atoi(av[1]));

	srand(time(0));
	for (unsigned int i = 0; i < sp2.getSize(); i++)
		sp2.addNumber(rand() % 1000);
	for (unsigned int i = 0; i < sp2.getSize(); i++)
		std::cout << sp2[i] << " ";
	std::cout << std::endl;

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}