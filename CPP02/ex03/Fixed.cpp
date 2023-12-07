#include "Fixed.hpp"

//	Constructors & Destructors
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

//	Copy assignment operator
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedPointVal = other.fixedPointVal;
	return *this;
}

//	Member functions
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
{
	return (static_cast<float>(fixedPointVal /
			static_cast<float>(1 << fractBits)));
}

int	Fixed::toInt() const
{ return (fixedPointVal >> fractBits); }

//	Static member functions
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{ return (a < b) ? a : b; }

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{ return (a < b) ? a : b; }

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{ return (a > b) ? a : b; }

const Fixed&	Fixed::max(const Fixed&a, const Fixed& b)
{ return (a > b) ? a : b; }

//	Comparison operators
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

// Arithmetic operators
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

// Increment / Decrement operators
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

//	Insertion operator
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

//
Fixed	Fixed::abs() const
{
	if (fixedPointVal < 0)
		return Fixed(-this->fixedPointVal);
	return *this;
}
