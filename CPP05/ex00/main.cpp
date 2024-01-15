#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "Test 1:" << std::endl;
	try
	{
		Bureaucrat	nisciun;

		std::cout << nisciun << std::endl;
		nisciun.promote(23);
		std::cout << nisciun << std::endl;
		nisciun.promote(123); //	should print "Grade too high"
		std::cout << nisciun << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Known exception: " << ex.what() << std::endl;
	}

	std::cout << "Test 2:" << std::endl;
	try
	{
		Bureaucrat	qualcun;

		std::cout << qualcun << std::endl;
		qualcun.demote(23);
		std::cout << qualcun << std::endl;
		qualcun.demote(123);
		std::cout << qualcun << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Known exception: " << ex.what() << std::endl;
	}

	std::cout << "Test 3:" << std::endl;
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

	// catch (...)
	// {
	// 	std::cout << "Unknown excxeption" << std::endl;
	// }

	return 0;
}
