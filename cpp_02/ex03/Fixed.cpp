#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_point_value(0) {}

Fixed::Fixed(const int i_value)
{
	this->fixed_point_value = i_value << this->fractional_bits;
}

Fixed::Fixed(const float f_value)
{
	this->fixed_point_value = roundf(f_value * (float)(1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed(void) {}

/* --------------------------------------------------------------------------------- */
Fixed	&Fixed::operator=(const Fixed &other)
{	
	if (this != &other)
		this->fixed_point_value = other.getRawBits();
	
	return (*this);
}

/* `````````````````````````````````````````````````````````````````````````````````` */

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

/* `````````````````````````````````````````````````````````````````````````````````` */

Fixed	Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

/* `````````````````````````````````````````````````````````````````````````````````` */

	Fixed	&Fixed::operator++(void)
	{
		this->setRawBits(this->getRawBits() + 1);
		return (*this);
	}

	Fixed	Fixed::operator++(int)
	{
		float	tmp;

		tmp = this->toFloat();
		this->setRawBits(this->getRawBits() + 1);

		return (Fixed(tmp));
	}

	Fixed	&Fixed::operator--(void)
	{
		this->setRawBits(this->getRawBits() - 1);
		return (*this);
	}

	Fixed	Fixed::operator--(int)
	{
		float	tmp;

		tmp = this->toFloat();
		this->setRawBits(this->getRawBits() - 1);

		return (Fixed(tmp));
	}

/* --------------------------------------------------------------------------------- */

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_value / (float)(1 << this->fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->fractional_bits);
}

/* `````````````````````````````````````````````````````````````````````````````````` */

int	Fixed::getRawBits(void) const {return (this->fixed_point_value);}

void	Fixed::setRawBits(int const raw) {this->fixed_point_value = raw;}

/* `````````````````````````````````````````````````````````````````````````````````` */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*====================================================================================== */
std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
