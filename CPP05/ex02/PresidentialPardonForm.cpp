#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardon", 25, 5), _target("None")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardon", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{ *this = copy; }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}


const std::string	PresidentialPardonForm::getTarget() const
{ return _target; }

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkForm(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
