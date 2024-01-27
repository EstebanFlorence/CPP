#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{ *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		;
	return *this;
}


// double	convertDouble(const std::string& literal)
// {

// }

// float	convertFloat(const std::string& literal)
// {
	
// }

// int	convertInt(const std::string& literal)
// {
	
// }

void	convertChar(const std::string& literal)
{
	char	c = static_cast <char> (literal[0]);

		std::cout << "char : \'" << c << "\'" << std::endl;
		std::cout << "int : \'" << static_cast <int> (c) << "\'" << std::endl;
		std::cout << "float : \'" << static_cast <float> (c) << "\'" << std::endl;
		std::cout << "double : \'" << static_cast <double> (c) << "\'" << std::endl;
	

}

int	checkType(const std::string& literal);

void	ScalarConverter::convert(const std::string& literal)
{
	int	type = checkType(literal);
	switch (type)
	{
		case 1:
			convertChar(literal);
			break;

		default:
			break;
	}

}
