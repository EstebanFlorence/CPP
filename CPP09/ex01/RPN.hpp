#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <exception>
# include <cerrno>
# include <sstream>
# include <cstdlib>
# include <climits>
# include <limits>
# include <stack>

class	RPN
{
	private:
		std::string		expression;
		std::stack<int>	numbers;
		int				result;

	public:
		RPN();
		RPN(const std::string& s);
		RPN(const RPN& copy);
		~RPN();
		RPN&	operator=(const RPN& other);

		bool				evaluateRPN();
		int				calculate(const char& c);
		bool				isOperator(const std::string& s);
		bool				isNumber(const std::string& s);
		void				setExpression(const std::string& s);
		const std::string&	getExpression() const;
		int				getResult() const;
		bool				error();

};

#endif