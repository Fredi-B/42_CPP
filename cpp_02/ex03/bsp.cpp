#include "Fixed.hpp"
#include "Point.hpp"

float	calc_area(Point const a, Point const b, Point const c);

/* checks if point is inside triangle (a, b, c) 
see https://www.youtube.com/watch?v=qObJQesvZUU */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	abc;
	float	pab;
	float	pbc;
	float	pac;

	abc = calc_area(a, b, c);
	pab = calc_area(point, a, b);
	pbc = calc_area(point, b, c);
	pac = calc_area(point, a, c);

	/* check if point is at the edge */
	if (pab == 0 || pbc == 0 || pac == 0)
		return (false);
	/* check if the three sub triangles combined are as big as the original */
	else if (pab + pbc + pac == abc)
		return (true);
	return (false);
}

/* calculates the size of the triangle area */
float	calc_area(Point const a, Point const b, Point const c)
{
	float	area;

	area = (
			a.get_float_x() * (b.get_float_y() - c.get_float_y())
			+ (b.get_float_x() * (c.get_float_y() - a.get_float_y()))
			+ (c.get_float_x() * (a.get_float_y() - b.get_float_y()))
		) / 2;

	if (area >= 0)
		return (area);
	else
		return (area * - 1);
}
