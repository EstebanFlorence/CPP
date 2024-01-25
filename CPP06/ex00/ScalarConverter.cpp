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

void	ScalarConerter::stoc(const std::string& literal)
{
	if (isValidChar(literal))
		std::cout << "char : \'" << literal[0] << "\'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

}

bool	ScalarConerter::isValidChar(const std::string& literal)
{
	if (literal.size() == 1)
	{
		if (literal[0] < 32 || literal[0] > 126)
			return false;
	}
	return true;
}

bool	ScalarConerter::isPseudoLiteral(const std::string& literal)
{
	if (literal != "-inff" && literal != "+inff" &&
		literal != "-inf" && literal != "+inf" && literal != "nan")
		return false;
	return true;
}

void	ScalarConerter::convert(const std::string& literal)
{

	stoc(literal);

}
