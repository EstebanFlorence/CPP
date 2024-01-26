#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <typeinfo>

class	ScalarConerter
{
	private:
	ScalarConerter();
	ScalarConerter(const ScalarConerter& copy);
	ScalarConerter&	operator=(const ScalarConerter& other);

	static void	stoc(const std::string& literal);
	static void	stoi(const std::string& literal);
	static void	stof(const std::string& literal);
	static void	stod(const std::string& literal);

	static bool	isChar(const std::string& literal);
	static bool	isInt(const std::string& literal);
	static bool	isFloat(const std::string& literal);
	static bool	isDouble(const std::string& literal);

	static char		convertChar(const std::string& literal);
	static int		convertInt(const std::string& literal);
	static float	convertFloat(const std::string& literal);
	static double	convertDouble(const std::string& literal);

	static bool	isPseudoLiteral(const std::string& literal);

	public:
	~ScalarConerter();

	static void	convert(const std::string& literal);
};

#endif