#include "Fixed.hpp"

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

Fixed&	Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointVal = other.fixedPointVal;
	return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;

}

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