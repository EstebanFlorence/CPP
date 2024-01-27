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
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
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
	if (literal != "-inff" && literal != "+inff" && literal == "nanf" &&
		literal != "-inf" && literal != "+inf" && literal != "nan")
		return false;
	return true;
}

int	checkType(const std::string& literal)
{
	if (isChar(literal))
		return 1;
	// if (isInt(literal))
	// 	stoi(literal);
	return 0;
}
