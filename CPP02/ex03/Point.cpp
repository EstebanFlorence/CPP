#include "Point.hpp"

Point::Point()
: x(0), y(0)
{}

Point::Point(const float x, const float y)
: x(x), y(y)
{}

Point::Point(const Point& other)
: x(other.x), y(other.y)
{}

Point::~Point() {}

Point&	Point::operator=(const Point& other)
{
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
