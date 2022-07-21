#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main(void)
{
	Point	point( 10, 15 );
	Point	a( 0, 0 );
	Point	b( 20, 0 );
	Point	c( 10, 30 );

	std::cout << "Inside triangle: " << bsp( a, b, c, point ) << std::endl;

	// point2 is on edge of triangle
	Point	point2( 10, 0 );
	Point	a2( 0, 0 );
	Point	b2( 20, 0 );
	Point	c2( 10, 30 );

	std::cout << "Point is on edge: " << bsp( a2, b2, c2, point2 ) << std::endl;

	// point3 is equal to vertex a3
	Point	point3( 10, 30 );
	Point	a3( 0, 0 );
	Point	b3( 20, 0 );
	Point	c3( 10, 30 );

	std::cout << "point == vertex: " << bsp( a3, b3, c3, point3 ) << std::endl;


	// point outside triangle
	Point	point4( 9, 30 );
	Point	a4( 0, 0 );
	Point	b4( 20, 0 );
	Point	c4( 10, 30 );

	std::cout << "point outside triangle: " << bsp( a4, b4, c4, point4 ) << std::endl;
	return (0);
}
