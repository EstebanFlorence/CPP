#include "Intern.hpp"

class	AForm;

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{ *this = copy; }

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm*	Intern::makeForm(const std::string& formType, const std::string& formTarget)
{
	std::string	types[3] = {"shrubbery", "robot", "presidential"};
	int	i;
	for (i = 0; i < 3; i++)
	{
		if (formType.find(types[i]) != std::string::npos)
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return new ShrubberyCreationForm(formTarget);
		case 1:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(formTarget);
		default:
			std::cout << "Form type not found!" << std::endl;

	}
	return NULL;
}
