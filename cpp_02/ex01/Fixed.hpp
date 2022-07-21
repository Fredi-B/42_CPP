#ifndef FIXED_HPP
#define	FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:

	Fixed(void);
	Fixed(const int i_value);
	Fixed(const float f_value);
	Fixed(const Fixed &other);
	~Fixed(void);

/* ``````````````````````````````````````````````````````` */
	Fixed	&operator=(const Fixed &other);

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
private:

	int					fixed_point_value;
	static const int	fractional_bits = 8;

};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif