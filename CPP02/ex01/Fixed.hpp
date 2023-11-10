#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					fixedPointVal;
		static const int	fractBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();

	public:
		Fixed&	operator=(const Fixed& other);

	public:
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif