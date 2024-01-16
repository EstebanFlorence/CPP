#include "Form.hpp"

Form::Form()
: _name("Default"), _signGrade(MIN_GRADE), _execGrade(MIN_GRADE / 2), _signedStatus(false)
{}

Form::Form(const Form& copy)
: _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade)//, _signedStatus(copy._signedStatus)
{ *this = copy; }

Form::Form(const std::string& name, int signGrade, int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signedStatus(false)
{ checkGrades(); }

Form::~Form() {}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signedStatus = other._signedStatus;
	return *this;
}


void	Form::checkGrades() const
{
	if (_signGrade < MAX_GRADE || _execGrade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_signGrade > MIN_GRADE || _execGrade > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string	Form::getName() const
{ return _name; }

int	Form::getSignGrade() const
{ return _signGrade; }

int	Form::getExecuteGrade() const
{ return _execGrade; }

bool	Form::isSigned() const
{ return _signedStatus; }

void	Form::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() <= getSignGrade())
		_signedStatus = true;
	else
		throw GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException()
: _msg("Grade too high!")
{}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg)
: _msg(msg)
{}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Form::GradeTooHighException::what() const throw()
{ return _msg.c_str(); }


Form::GradeTooLowException::GradeTooLowException()
: _msg("Grade too low!")
{}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg)
: _msg(msg)
{}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Form::GradeTooLowException::what() const throw()
{ return _msg.c_str(); }


std::ostream&	operator<<(std::ostream& os, const Form& other)
{
	os << other.getName() << " Form"
	<< ", grade to sign " << other.getSignGrade()
	<< ", grade to execute " << other.getExecuteGrade()
	<< ", is " << (other.isSigned() ? "" : "not ") << "signed.";
	return os;
}
