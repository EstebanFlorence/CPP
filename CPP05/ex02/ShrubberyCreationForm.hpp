#ifndef SHRUBBERY_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		const std::string	getTarget() const;
		void				execute(const Bureaucrat& executor) const;
};

 #endif