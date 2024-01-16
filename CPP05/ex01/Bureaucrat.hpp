#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		void	checkGrade() const;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(const std::string& name, const int grade);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other);

		const std::string&	getName() const;
		int					getGrade() const;
		void				promote(const int grades);
		void				demote(const int grades);
		void				signForm(Form& form) const;

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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other);

#endif