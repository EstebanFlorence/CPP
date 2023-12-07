#include "Point.hpp"

int main( void )
{
	Point	a(2.8, 3.7);
	Point	b(0.9, 0.9);
	Point	c(9.1, 1.4);
	Point	point(3.3, 2);

	if (bsp(a, b, c, point))
		std::cout << "IN" << std::endl;
	else
		std::cout << "OUT" << std::endl;

	return 0;
}
