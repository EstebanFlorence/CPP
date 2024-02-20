#include"RPN.hpp"

RPN::RPN()
: expression(NULL), result(0)
{}

RPN::RPN(const std::string& s)
: expression(s), result(0)
{}

RPN::RPN(const RPN& copy)
: expression(copy.expression), numbers(copy.numbers), result(copy.result)
{}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return *this;

	this->expression = other.expression;
	this->numbers = other.numbers;
	this->result = other.result;

	return *this;
}

//	a + b * c = a b c * + => a d +

bool	RPN::evaluateRPN()
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (numbers.size() < 2)
				return error();
			numbers.push(calculate(token[0]));
		}
		else if (isNumber(token))
			numbers.push(std::atoi(token.c_str()));
		else
			return error();
	}
	if (numbers.size() == 1)
	{
		result = numbers.top();
		return true;
	}
	return error();
}

int	RPN::calculate(const char& c)
{
	int	b = numbers.top();
	numbers.pop();
	int	a = numbers.top();
	numbers.pop();

	switch (c)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
	return (0);
}

bool	RPN::isOperator(const std::string& s)
{
	if (s.size() != 1 || s.find_first_of("+-*/") == std::string::npos)
		return false;

	return true;
}

bool	RPN::isNumber(const std::string& s)
{
	errno = 0;
	char*		endptr = NULL;
	long long	num = std::strtol(s.c_str(), &endptr, 10);

	if ((errno != 0 && num == 0) || 
		static_cast<std::string::size_type>(endptr - s.c_str()) != s.size() || 
		num < std::numeric_limits<int>::min() || 
		num > std::numeric_limits<int>::max())
		return false;
	// numbers.push(static_cast<int>(num));

	return true;
}

void	RPN::setExpression(const std::string& s)
{ expression = s; }

const std::string&	RPN::getExpression() const
{ return expression; }

int	RPN::getResult() const
{ return result; }

bool	RPN::error()
{
	std::cerr << "Error" << std::endl;
	return false;
}
