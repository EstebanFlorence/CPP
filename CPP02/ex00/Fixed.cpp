#include "Fixed.hpp"

Fixed::Fixed()
: fixedPointVal(0)
{
	std::cout << ITALIC "Fixed Default Constructor called" CLR_RMV << std::endl;
}

Fixed::Fixed(const Fixed& other)
: fixedPointVal(other.fixedPointVal)
{
	std::cout << ITALIC "Fixed Copy Constructor called" CLR_RMV << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << ITALIC "Fixed Copy Assignment operator called" CLR_RMV << std::endl;
	if (this != &other)
		this->fixedPointVal = other.fixedPointVal;
	return *this;
}

Fixed::~Fixed()
{
    	std::cout << ITALIC "Fixed Default Destructor called" CLR_RMV << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << ITALIC "getRawBits() Fixed member function called" CLR_RMV << std::endl;
	return fixedPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << ITALIC "setRawBits() Fixed member function called" CLR_RMV << std::endl;
	fixedPointVal = raw;
}
