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


int	getPrecision(const std::string& literal)
{
	size_t	decimalPos = literal.find('.');
	int		precision = 1;

	if (decimalPos != std::string::npos)
		precision = static_cast<int>(literal.length() - decimalPos - 
			(literal.find('f') != std::string::npos ? 2 : 1));
	
	return precision;
}

// static void	convertDouble(const std::string& literal)
// {

// }

static void	convertFloat(const std::string& literal)
{
	float	n = static_cast<float>(std::atof(literal.c_str()));

	std::cout << "char : \'" << static_cast<char>(n) << "\'" << std::endl;	// Needs checks
	std::cout << "int : " << static_cast<int>(n) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(getPrecision(literal)) << n << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(getPrecision(literal)) << static_cast<double>(n) << std::endl;
}

static void	convertInt(const std::string& literal)
{
	int	n = std::atoi(literal.c_str());

	std::cout << "char : \'" << static_cast<char>(n) << "\'" << std::endl;	// Needs checks
	std::cout << "int : " << n << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(getPrecision(literal)) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(getPrecision(literal)) << static_cast<double>(n) << std::endl;
}

static void	convertChar(const std::string& literal)
{
	char	c = static_cast <char> (literal[0]);

	std::cout << "char : \'" << c << "\'" << std::endl;
	std::cout << "int : " << static_cast <int> (c) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(getPrecision(literal)) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(getPrecision(literal)) << static_cast<double>(c) << std::endl;

}

int	checkType(const std::string& literal);

void	ScalarConverter::convert(const std::string& literal)
{
	int	type = checkType(literal);
	switch (type)
	{
		// case 0:

		case 1:
			convertChar(literal);
			break;
		case 2:
			convertInt(literal);
			break;
		case 3:
			convertFloat(literal);
			break;
		default:
			std::cerr << "Invalid argument:\n<literal> types allowed: char, int, float, double" << std::endl;
			break;
	}

}
