#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;

	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("lobotomy request", "Bender");
		if (rrf)
			std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}
