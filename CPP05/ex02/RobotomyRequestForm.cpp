#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequest", 72, 45), _target("None")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequest", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{ *this = copy; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}


const std::string	RobotomyRequestForm::getTarget() const
{ return _target; }

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkForm(executor);
	srand(time(0));
	switch (rand() % 2)
	{
		case 0:
			std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
			break;
		case 1:
			std::cout << "The robotomy for " << getTarget() << " failed!" << std::endl;
			break;
	}
}
