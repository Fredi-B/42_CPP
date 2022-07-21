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
/* --------------------------------------------------------------------------------- */
	Fixed	&operator=(const Fixed &other);
/* `````````````````````````````````````````````````````````````````````````````````` */
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
/* `````````````````````````````````````````````````````````````````````````````````` */
	Fixed	operator+(const Fixed &other);
	Fixed	operator-(const Fixed &other);
	Fixed	operator*(const Fixed &other);
	Fixed	operator/(const Fixed &other);
/* `````````````````````````````````````````````````````````````````````````````````` */
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
/* --------------------------------------------------------------------------------- */
	float	toFloat(void) const;
	int		toInt(void) const;
/* `````````````````````````````````````````````````````````````````````````````````` */
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
/* `````````````````````````````````````````````````````````````````````````````````` */
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
/*====================================================================================== */
private:

	int					fixed_point_value;
	static const int	fractional_bits = 8;

};
/*====================================================================================== */
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif