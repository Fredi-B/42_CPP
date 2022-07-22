#include "Fixed.hpp"

Fixed::Fixed(void) : fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = i_value << this->fractional_bits;
}

Fixed::Fixed(const float f_value)
{
	this->fixed_point_value = roundf(f_value * (float)(1 << this->fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* ```````````````````````````````````````````````````````````````````````````` */

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->fixed_point_value = other.getRawBits();
	
	return (*this);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_value / (float)(1 << this->fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->fractional_bits);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int	Fixed::getRawBits(void) const {return (this->fixed_point_value);}

void	Fixed::setRawBits(int const raw) {this->fixed_point_value = raw;}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
