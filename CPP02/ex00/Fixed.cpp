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

Fixed&	Fixed::operator=(const Fixed& other)
{
    std::cout << ITALIC "Copy assignment operator called" CLR_RMV << std::endl;
	if (this != &other)
		this->fixedPointVal = other.fixedPointVal;
	return *this;
}

Fixed::~Fixed()
{
    std::cout << ITALIC "Destructor called" CLR_RMV << std::endl;
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
