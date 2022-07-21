#include "Fixed.hpp"

int	main(void)
{
	Fixed	a(0);
	Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed	c(0);

	const Fixed	d(10);
	const Fixed	e(15);

/* check 6 comparison operators */
	// if (a > b)
	// 	std::cout << "a is bigger than b" << std::endl;
	// else
	// 	std::cout << "a is not bigger than b" << std::endl;
	// if (a < b)
	// 	std::cout << "a is smaller than b" << std::endl;
	// else
	// 	std::cout << "a is not smaller than b" << std::endl;
	// if (a >= b)
	// 	std::cout << "a is >= b" << std::endl;
	// else
	// 	std::cout << "a is not >= b" << std::endl;
	// if (a <= b)
	// 	std::cout << "a is <= b" << std::endl;
	// else
	// 	std::cout << "a is not <= b" << std::endl;
	// if (a == b)
	// 	std::cout << "a is equal to b" << std::endl;
	// else
	// 	std::cout << "a is not equal to b" << std::endl;
	// if (a != b)
	// 	std::cout << "a is not equal to b" << std::endl;
	// else
	// 	std::cout << "a is equal to b" << std::endl;

/* check 4 arithmetic operators */
	// c = a + b;
	// std::cout << c << std::endl;
	// c = a - b;
	// std::cout << c << std::endl;
	// c = a * b;
	// std::cout << c << std::endl;
	// c = a / b;
	// std::cout << c << std::endl;

/* check 4 increment/decrement operators */
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	// std::cout << a << std::endl;
	// std::cout << --a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a-- << std::endl;
	// std::cout << a << std::endl;

/* check 4 public overloaded member functions */
	// std::cout << Fixed::min(a, b) << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	// std::cout << Fixed::min(e, d) << std::endl;
	// std::cout << Fixed::max(e, d) << std::endl;
	
	return (0);
}
