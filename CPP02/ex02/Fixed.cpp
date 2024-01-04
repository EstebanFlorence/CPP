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
{
	return (static_cast<float>(fixedPointVal /
			static_cast<float>(1 << fractBits)));
}

int	Fixed::toInt() const
{ return (fixedPointVal >> fractBits); }

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{ return (a < b) ? a : b; }

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{ return (a < b) ? a : b; }

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{ return (a > b) ? a : b; }

const Fixed&	Fixed::max(const Fixed&a, const Fixed& b)
{ return (a > b) ? a : b; }

bool	Fixed::operator>(const Fixed& other) const
{ return this->fixedPointVal > other.fixedPointVal; }

bool	Fixed::operator<(const Fixed& other) const
{ return this->fixedPointVal < other.fixedPointVal; }

bool	Fixed::operator>=(const Fixed& other) const
{ return this->fixedPointVal >= other.fixedPointVal; }

bool	Fixed::operator<=(const Fixed& other) const
{ return this->fixedPointVal <= other.fixedPointVal; }

bool	Fixed::operator==(const Fixed& other) const
{ return this->fixedPointVal == other.fixedPointVal; }

bool	Fixed::operator!=(const Fixed& other) const
{ return this->fixedPointVal != other.fixedPointVal; }

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.fixedPointVal = this->fixedPointVal + other.fixedPointVal;
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.fixedPointVal = this->fixedPointVal - other.fixedPointVal;
	return result;
}
Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.fixedPointVal = (this->fixedPointVal * other.fixedPointVal) >> fractBits;
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.fixedPointVal = (this->fixedPointVal << fractBits) / other.fixedPointVal;
	return result;
}

Fixed&	Fixed::operator++()
{
	this->fixedPointVal++;
	return *this;
}

Fixed&	Fixed::operator--()
{
	this->fixedPointVal--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->fixedPointVal++;
	return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	this->fixedPointVal--;
	return old;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
