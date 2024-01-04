#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

};

#endif