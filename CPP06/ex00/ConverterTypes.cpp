#include <iostream>
#include <climits>
#include <limits>
#include <cstdlib>
#include <cerrno>

bool	isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.size() == 1)
			return false;
		i = 1;
	}

	//	Allow leading 0s?
	if (literal.size() > 1 && literal[i] == '0')
		return false;

	bool	decimalPoint = false;
	for (; i < literal.size(); i++)
	{
		if (literal[i] == '.')
		{
			if (decimalPoint)
				return false;
			decimalPoint = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	if (!decimalPoint)
		return false;

	errno = 0;
	char*	end;
	double	num = std::strtod(literal.c_str(), &end);
	if (errno == ERANGE)
		return false;
	if (num < std::numeric_limits<double>::min() || num > std::numeric_limits<double>::max())
		return false;

	return true;
}

bool	isFloat(const std::string& literal)
{
	if (literal.empty() || literal[literal.size() - 1] != 'f')
		return false;

	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.size() == 1)
			return false;
		i = 1;
	}

	//	Allow leading 0s?
	if (literal.size() > 1 && literal[i] == '0')
		return false;

	bool	decimalPoint = false;
	for (; i < literal.size() - 1; i++)
	{
		if (literal[i] == '.')
		{
			if (decimalPoint)
				return false;
			decimalPoint = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	if (!decimalPoint)
		return false;

	errno = 0;
	char*	end;
	float	num = std::strtof(literal.c_str(), &end);
	if (errno == ERANGE)
		return false;
	// if (end != literal.c_str() + literal.size())
	// 	return false;
	if (num < std::numeric_limits<float>::min() || num > std::numeric_limits<float>::max())
		return false;

	return true;
}

bool	isInt(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.size() == 1)
			return false;
		i = 1;
	}

	//	Allow leading 0s?
	if (literal.size() > 1 && literal[i] == '0')
		return false;

	for (; i < literal.size(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}

	errno = 0;
	char*		end;
	long long	num = std::strtol(literal.c_str(), &end, 10);
	if ((num == LONG_MAX || num == LONG_MIN) && errno == ERANGE)
		return false;
	// if (end != literal.c_str() + literal.size())
	// 	return false;
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return false;

	return true;
}

bool	isChar(const std::string& literal)
{
	if (literal.size() != 1)
		return false;
	if (std::isdigit(literal[0]) ||
		literal[0] < 32 || literal[0] > 126)
		return false;
	return true;
}

bool	isPseudoLiteral(const std::string& literal)
{
	if (literal != "-inff" && literal != "+inff" && literal != "nanf" &&
		literal != "-inf" && literal != "+inf" && literal != "nan")
		return false;
	return true;
}

int	checkType(const std::string& literal)
{
	if (isPseudoLiteral(literal))
		return 0;
	else if (isChar(literal))
		return 1;
	else if (isInt(literal))
		return 2;
	else if (isFloat(literal))
		return 3;
	else if (isDouble(literal))
		return 4;
	return -1;
}
