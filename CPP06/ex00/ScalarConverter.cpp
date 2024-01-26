#include "ScalarConverter.hpp"

ScalarConerter::ScalarConerter() {}

ScalarConerter::ScalarConerter(const ScalarConerter& copy)
{ *this = copy; }

ScalarConerter::~ScalarConerter() {}

ScalarConerter&	ScalarConerter::operator=(const ScalarConerter& other)
{
	if (this != &other)
		;
	return *this;
}


bool	ScalarConerter::isDouble(const std::string& literal)
{
	
}

bool	ScalarConerter::isFloat(const std::string& literal)
{
	
}

bool	ScalarConerter::isInt(const std::string& literal)
{

}

bool	ScalarConerter::isChar(const std::string& literal)
{
	if (!literal.size())
		return false;
	for  (size_t i = 0; i < literal.size(); i++)
	{
		if (i >= 3 || literal[i] < 32 || literal[i] > 126)
			return false;
	}
	return true;
}


double	ScalarConerter::convertDouble(const std::string& literal)
{

}

float	ScalarConerter::convertFloat(const std::string& literal)
{
	
}

int	ScalarConerter::convertInt(const std::string& literal)
{
	
}

char	ScalarConerter::convertChar(const std::string& literal)
{
	char	c = '\0';

	if (!isChar(literal))
		return c;
	size_t	isDigit = 0;
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (std::isdigit(literal[i]))
			isDigit++;
	}
	if (isDigit == literal.size())
	{
		int tmp = std::atoi(literal.c_str());
		if (tmp > 32 && tmp < 126)
			c = static_cast<char>(tmp);
		return c;
	}
	switch (literal.size())
	{
		case 1:
			c = literal[0];
			break;
		case 3:	// to handle?
			if (literal[0] == '\'' && literal[2] == '\'')
				c = literal[1];
			break;
		default:
			return false;
	}
	return c;
}


void	ScalarConerter::stod(const std::string& literal)
{

}

void	ScalarConerter::stof(const std::string& literal)
{

}

void	ScalarConerter::stoi(const std::string& literal)
{

}

void	ScalarConerter::stoc(const std::string& literal)
{
	char	c = convertChar(literal);

	if (c)
		std::cout << "char : \'" << c << "\'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

}


bool	ScalarConerter::isPseudoLiteral(const std::string& literal)
{
	if (literal != "-inff" && literal != "+inff" && literal == "nanf" &&
		literal != "-inf" && literal != "+inf" && literal != "nan")
		return false;
	return true;
}


void	ScalarConerter::convert(const std::string& literal)
{

	stoc(literal);

}
