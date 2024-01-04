#include "Fixed.hpp"

Fixed::Fixed()
: fixedPointVal(0)
{
	std::cout << ITALIC "Default constructor called" CLR_RMV << std::endl;
}

Fixed::Fixed(const Fixed& other)
: fixedPointVal(other.fixedPointVal)
{
	std::cout << ITALIC "Copy constructor called" CLR_RMV << std::endl;
}

Fixed::Fixed(const int value)
: fixedPointVal(value << fractBits)
{
	std::cout << ITALIC "Int constructor called" CLR_RMV << std::endl;
}

Fixed::Fixed(const float value)
: fixedPointVal(roundf(value * (1 << fractBits)))
{
	std::cout << ITALIC "Float constructor called" CLR_RMV << std::endl;
}

Fixed::~Fixed()
{
	std::cout << ITALIC "Destructor called" CLR_RMV << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << ITALIC "Copy assignment operator called" CLR_RMV << std::endl;
	if (this != &other)
		fixedPointVal = other.fixedPointVal;
	return *this;
}

int	Fixed::getRawBits() const
{
	std::cout << ITALIC "getRawBits member function called" CLR_RMV << std::endl;
	return fixedPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << ITALIC "setRawBits member function called" CLR_RMV << std::endl;
	fixedPointVal = raw;
}

float	Fixed::toFloat() const
{ return (static_cast<float>(fixedPointVal / static_cast<float>(1 << fractBits))); }

int	Fixed::toInt() const
{ return (fixedPointVal >> fractBits); }

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
