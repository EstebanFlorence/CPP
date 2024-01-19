#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signedStatus;

	protected:
		void	checkGrades() const;
		void	checkForm(const Bureaucrat& executor) const;

	public:
		AForm();
		AForm(const AForm& copy);
		AForm(const std::string& name, int signGrade, int execGrade);
		virtual ~AForm();
		AForm&	operator=(const AForm& other);

		const std::string			getName() const;
		int							getSignGrade() const;
		int							getExecuteGrade() const;
		bool						isSigned() const;
		void						beSigned(const Bureaucrat& bu);
		virtual const std::string	getTarget() const = 0;
		virtual void				execute(const Bureaucrat& executor) const = 0;

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

		class	IsNotSignedException : public std::exception
		{
			private:
				std::string	_msg;
			
			public:
				IsNotSignedException();
				IsNotSignedException(const std::string& msg);
				virtual ~IsNotSignedException() throw();

				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& other);

#endif