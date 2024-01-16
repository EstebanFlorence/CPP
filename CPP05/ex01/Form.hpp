#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signedStatus;

		void	checkGrades() const;

	public:
		Form();
		Form(const Form& copy);
		Form(const std::string& name, int signGrade, int execGrade);
		~Form();
		Form&	operator=(const Form& other);

		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		bool				isSigned() const;
		void				beSigned(const Bureaucrat& bu);

		class	GradeTooHighException : public std::exception
		{
			private:
				std::string	_msg;

			public:
				GradeTooHighException();
				GradeTooHighException(const std::string& msg);
				virtual ~GradeTooHighException() throw();

				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			private:
				std::string	_msg;

			public:
				GradeTooLowException();
				GradeTooLowException(const std::string& msg);
				virtual ~GradeTooLowException() throw();

				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& other);

#endif