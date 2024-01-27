#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <typeinfo>

class	ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter&	operator=(const ScalarConverter& other);

	public:
	~ScalarConverter();

	static void	convert(const std::string& literal);
};

#endif