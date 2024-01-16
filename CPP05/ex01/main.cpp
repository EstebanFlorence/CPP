#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "Test 1:" << std::endl;
	try
	{
		Bureaucrat	chad;
		Form		form;

		std::cout << chad << std::endl;
		std::cout << form << std::endl;
		chad.signForm(form);
		chad.demote(75);
		chad.signForm(form);
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	std::cout << "Test 2:" << std::endl;
	try
	{
		Bureaucrat	chad;
		Form		form;

		std::cout << chad << std::endl;
		std::cout << form << std::endl;
		chad.signForm(form);
		chad.demote(75);
		chad.signForm(form);
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	//	More tests to implement...

	return 0;
}
