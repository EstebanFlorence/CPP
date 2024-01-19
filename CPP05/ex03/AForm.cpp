#include "AForm.hpp"

AForm::AForm()
: _name("Default"), _signGrade(MIN_GRADE), _execGrade(MIN_GRADE / 2), _signedStatus(false)
{}

AForm::AForm(const AForm& copy)
: _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade)//, _signedStatus(copy._signedStatus)
{ *this = copy; }

AForm::AForm(const std::string& name, int signGrade, int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signedStatus(false)
{ checkGrades(); }

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signedStatus = other._signedStatus;
	return *this;
}


void	AForm::checkGrades() const
{
	if (_signGrade < MAX_GRADE || _execGrade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_signGrade > MIN_GRADE || _execGrade > MIN_GRADE)
		throw GradeTooLowException();
}

void	AForm::checkForm(const Bureaucrat& executor) const
{
	if (_signedStatus == false)
		throw IsNotSignedException();
	else if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

const std::string	AForm::getName() const
{ return _name; }

int	AForm::getSignGrade() const
{ return _signGrade; }

int	AForm::getExecuteGrade() const
{ return _execGrade; }

bool	AForm::isSigned() const
{ return _signedStatus; }

void	AForm::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() <= getSignGrade())
		_signedStatus = true;
	else
		throw GradeTooLowException();
}

AForm::GradeTooHighException::GradeTooHighException()
: _msg("Grade too high!")
{}

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg)
: _msg(msg)
{}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	AForm::GradeTooHighException::what() const throw()
{ return _msg.c_str(); }


AForm::GradeTooLowException::GradeTooLowException()
: _msg("Grade too low!")
{}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg)
: _msg(msg)
{}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	AForm::GradeTooLowException::what() const throw()
{ return _msg.c_str(); }


AForm::IsNotSignedException::IsNotSignedException()
: _msg("Form not signed!")
{}

AForm::IsNotSignedException::IsNotSignedException(const std::string& msg)
: _msg(msg)
{}

AForm::IsNotSignedException::~IsNotSignedException() throw() {}

const char*	AForm::IsNotSignedException::what() const throw()
{ return _msg.c_str(); }


std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	os << other.getName() << " AForm"
	<< ", grade to sign " << other.getSignGrade()
	<< ", grade to execute " << other.getExecuteGrade()
	<< ", is " << (other.isSigned() ? "" : "not ") << "signed.";
	return os;
}
