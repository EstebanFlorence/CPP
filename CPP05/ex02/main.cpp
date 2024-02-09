#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test1()
{
	try
	{
		ShrubberyCreationForm	shrubberyCreation("White House");
		RobotomyRequestForm		robotRequest("President");
		PresidentialPardonForm	presidentalPardon("Kodak Black");

		std::cout << shrubberyCreation << " Target: " << shrubberyCreation.getTarget() << std::endl;
		std::cout << robotRequest << " Target: " << robotRequest.getTarget() << std::endl;
		std::cout << presidentalPardon << " Target: " << presidentalPardon.getTarget() << std::endl;

		Bureaucrat	gardener("Willie", 123);
		Bureaucrat	researcher("Dr.Krieger", 69); // Grade to exec too low
		Bureaucrat	president("Donal Trump", 3);
		Bureaucrat	marvin("Marvin", 42);

		// shrubberyCreation.execute(gardener);	// Only throws an exception
		gardener.executeForm(shrubberyCreation);
		gardener.signForm(shrubberyCreation);
		// shrubberyCreation.execute(gardener);	// Only executes
		gardener.executeForm(shrubberyCreation);

		// robotRequest.execute(researcher);
		researcher.executeForm(robotRequest);
		researcher.signForm(robotRequest);
		// robotRequest.execute(researcher);
		researcher.executeForm(robotRequest);
		marvin.executeForm(robotRequest);

		president.executeForm(presidentalPardon);
		president.signForm(presidentalPardon);
		president.executeForm(presidentalPardon);

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

	return 0;
}
