#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreation", 145, 137), _target("None")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
: AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}


const std::string	ShrubberyCreationForm::getTarget() const
{ return _target; }

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkForm(executor);
	std::ofstream	ofile((getTarget() + "_shrubbery").c_str());

	ofile << "		# #### ####" << std::endl;
	ofile << "	### \\/#|### |/####" << std::endl;
	ofile << "	##\\/#/ \\||/##/_/##/_#" << std::endl;
	ofile << "	###  \\/###|/ \\/ # ###" << std::endl;
	ofile << "##_\\_#\\_\\## | #/###_/_####" << std::endl;
	ofile << "## #### # \\ #| /  #### ##/##" << std::endl;
	ofile << "__#_--###`  |{,###---###-~" << std::endl;
	ofile << "			\\ }{" << std::endl;
	ofile << "			}}{" << std::endl;
	ofile << "			}}{" << std::endl;
	ofile << "		ejm  {{}" << std::endl;
	ofile << "	, -=-~{ .-^- _" << std::endl;
	ofile << "			`}" << std::endl;
	ofile << "			{" << std::endl;
	ofile.close();
}

AForm*	ShrubberyCreationForm::newForm(const std::string& target) const
{ return new ShrubberyCreationForm(target); }
