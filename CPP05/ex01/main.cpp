#include "Bureaucrat.hpp"

void	test2()
{
	try
	{
		Bureaucrat	chad("Chad", 7);
		Bureaucrat	wassie(chad);
		Form		highGradeForm("Based", 23, 3);
		Form		lowGradeForm("LolEz", 123, 142);

		std::cout << chad << std::endl;
		std::cout << wassie << std::endl;
		std::cout << highGradeForm << std::endl;
		chad.signForm(highGradeForm);
		wassie.demote(120);
		wassie.signForm(lowGradeForm);
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
		Form	tooLowGradeForm("Bomboclat", 150, 151);
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try
	{
		Form	tooHighGradeForm("Bomboclat", 1, 0);
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}

int	main()
{
	std::cout << "Test 1:" << std::endl;
	test1();

	std::cout << "Test 2:" << std::endl;
	test2();

	return 0;
}
