#ifndef POINT_HPP
#define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &other);
	~Point(void);

	Point	&operator=(Point const &other);

	Fixed	get_x(void) const;
	Fixed	get_y(void) const;
	float	get_float_x(void) const;
	float	get_float_y(void) const;

private:
	Fixed const	x;
	Fixed const	y;
};

#endif