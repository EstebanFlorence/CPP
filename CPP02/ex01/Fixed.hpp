#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"

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
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		Fixed&	operator=(const Fixed& other);

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif