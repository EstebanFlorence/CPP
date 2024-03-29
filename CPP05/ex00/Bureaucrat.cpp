#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("MidBureaucrat"), _grade(MIN_GRADE / 2)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
: _name(copy._name)
{ *this = copy; }

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
: _name(name), _grade(grade)
{ checkGrade(); }

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}


void	Bureaucrat::checkGrade() const
{
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_grade > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string&	Bureaucrat::getName() const
{ return _name; }

int	Bureaucrat::getGrade() const
{ return _grade; }

void	Bureaucrat::promote(const int grades)
{
	_grade -= grades;
	checkGrade();
}

void	Bureaucrat::demote(const int grades)
{
	_grade += grades;
	checkGrade();
}


Bureaucrat::GradeTooHighException::GradeTooHighException()
: _msg("Grade too high!")
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg)
: _msg(msg)
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{ return _msg.c_str(); }


Bureaucrat::GradeTooLowException::GradeTooLowException()
: _msg("Grade too low!")
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg)
: _msg(msg)
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{ return _msg.c_str(); }



std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os;
}
