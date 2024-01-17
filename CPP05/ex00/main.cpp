#include "Bureaucrat.hpp"

void	test3()
{
	try
	{
		Bureaucrat	karen("Karen", 42);

		std::cout << karen << std::endl;
		karen.promote(23);
		std::cout << karen << std::endl;
		karen.demote(33);
		std::cout << karen << std::endl;
		karen.promote(10);
		std::cout << karen << std::endl;

		Bureaucrat	chad("Chad", 69);
		std::cout << chad << std::endl;
		chad = karen;
		std::cout << chad << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Known exception: " << ex.what() << std::endl;
	}
}

void	test2()
{
	try
	{
		Bureaucrat	tooHighGradeBu("Bomboclat", 0);
	}
	catch (std::exception& ex)
	{
		std::cout << "Known exception: " << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat	tooLowGradeBu("Bomboclat", 151);
	}
	catch (std::exception& ex)
	{
		std::cout << "Known exception: " << ex.what() << std::endl;
	}
}

void	test1()
{
	try
	{
		Bureaucrat	nisciun;

		std::cout << nisciun << std::endl;
		nisciun.promote(23);
		std::cout << nisciun << std::endl;
		nisciun.promote(123);
		std::cout << nisciun << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Known exception: " << ex.what() << std::endl;
	}
}

int	main()
{
	std::cout << "Test 1:" << std::endl;
	test1();

	std::cout << "Test 2:" << std::endl;
	test2();

	std::cout << "Test 3:" << std::endl;
	test3();

	return 0;
}
