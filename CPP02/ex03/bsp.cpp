#include "Point.hpp"

Fixed	area(const Point& a, const Point& b, const Point& c)
{
	return (a.getX() * (b.getY() - c.getY()) +
			b.getX() * (c.getY() - a.getY()) +
			c.getX() * (a.getY() - b.getY())).abs().toFloat() / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = area(a, b, c);
	Fixed	areaABP = area(a, b, point);
	Fixed	areaAPC = area(a, point, c);
	Fixed	areaPBC = area(point, b, c);

	return areaABC == (areaABP + areaAPC + areaPBC);
}
