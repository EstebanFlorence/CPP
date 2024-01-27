# include <iostream>
# include <limits>
# include <typeinfo>

// bool	isDouble(const std::string& literal)
// {
	
// }

// bool	isFloat(const std::string& literal)
// {
	
// }

bool	isInt(const std::string& literal)
{
	if (literal.empty() || std::isspace(static_cast<unsigned char>(literal.front())) || std::isspace(static_cast<unsigned char>(literal.back())))
		return false;

	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.size() == 1)
			return false;
		i = 1;
	}

	if (literal.size() > 1 && literal[i] == '0')
		return false;

	for (; i < literal.size(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}

	char*		end;
	long long	num = std::strtol(literal.c_str(), &end, 10);
	errno = 0;
	if ((num == LONG_MAX || num == LONG_MIN) && errno == ERANGE)
		return false;
	if (end != literal.c_str() + literal.size())
		return false;
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
	if (isChar(literal))
		return 1;
	if (isInt(literal))
		return 2;
	return 0;
}