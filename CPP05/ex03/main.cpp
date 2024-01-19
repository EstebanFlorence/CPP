#include "Intern.hpp"

void	test2()
{
	try
	{

	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}

void	test1()
{
	try
	{

	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try
	{

	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}

int	main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	// std::cout << "Test 1:" << std::endl;
	// test1();

	// std::cout << "Test 2:" << std::endl;
	// test2();

	return 0;
}
