#include "Point.hpp"

Fixed	area(const Point& a, const Point& b, const Point& c)
{
	return 0.5 * std::abs((a.getX() - b.getX()) * (a.getY() - c.getY())
						- (a.getY() - b.getY()) * (a.getX() - c.getY()));
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	
}
