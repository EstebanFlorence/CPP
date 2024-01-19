#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	AForm;

class	Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern&	operator=(const Intern& other);

		AForm*	makeForm(const std::string& formType, const std::string& formTarget);
};

#endif
