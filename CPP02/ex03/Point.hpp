#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define GREEN_DARK "\033[0;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

class	Point
{
	private:
		Fixed	x;
		Fixed	y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();

		Point&	operator=(const Point& other);

		Fixed	getX() const;
		Fixed	getY() const;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif