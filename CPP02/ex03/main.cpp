#include "Point.hpp"

int main( void )
{
	Point	a(1, 3);
	Point	b(2.24, 0.73);
	Point	c(5.48, 2.57);
	Point	point(3.86, 1.33);

	if (bsp(a, b, c, point))
		std::cout << GREEN "IN" CLR_RMV << std::endl;
	else
		std::cout << RED "OUT" CLR_RMV << std::endl;

	return 0;
}
