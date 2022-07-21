#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const &other) : x(other.get_x()), y(other.get_y()) {}

Point::~Point(void) {}

Point	&Point::operator=(Point const &other)
{
	if (this != &other)
	{}
	return (*this);
}

Fixed	Point::get_x(void) const {return (this->x);}

Fixed	Point::get_y(void) const {return (this->y);}

float	Point::get_float_x(void) const {return (this->x.toFloat());}

float	Point::get_float_y(void) const {return (this->y.toFloat());}
