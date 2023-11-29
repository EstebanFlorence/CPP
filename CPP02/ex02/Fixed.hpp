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
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed&a, const Fixed& b);

		Fixed&	operator=(const Fixed& other);

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif