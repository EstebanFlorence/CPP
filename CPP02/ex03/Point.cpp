#include "Point.hpp"

Point::Point()
: x(0), y(0)
{
	std::cout << ITALIC "Point Default Constructor called" CLR_RMV << std::endl;
}

Point::Point(const float x, const float y)
: x(x), y(y)
{
	std::cout << ITALIC "Point Parameterized Constructor called" CLR_RMV << std::endl;
}

Point::Point(const Point& other)
: x(other.x), y(other.y)
{
	std::cout << ITALIC "Point Copy Constructor called" CLR_RMV << std::endl;}

Point::~Point()
{
	std::cout << ITALIC "Point Default Destructor called" CLR_RMV << std::endl;
}

Point&	Point::operator=(const Point& other)
{
	std::cout << ITALIC "Point Copy Assignment operator called" CLR_RMV << std::endl;
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Fixed	Point::getX() const
{ return this->x; }

Fixed	Point::getY() const
{ return this->y; }
