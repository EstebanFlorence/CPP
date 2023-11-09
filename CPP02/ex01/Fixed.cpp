#include "Fixed.hpp"

//	~ Constructors & Destructors ~
Fixed::Fixed()
: fixedPointVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
: fixedPointVal(other.fixedPointVal)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
: fixedPointVal(value << fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
: fixedPointVal(roundf(value * (1 << fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//	~ Overload operators ~
Fixed&	Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedPointVal = other.fixedPointVal;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

//	~ Member functions ~
int	Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
	return fixedPointVal;
}

void	Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
	fixedPointVal = raw;
}

float	Fixed::toFloat() const
{ return (static_cast<float>(fixedPointVal / static_cast<float>(1 << fractBits))); }

int	Fixed::toInt() const
{ return (fixedPointVal >> fractBits); }
