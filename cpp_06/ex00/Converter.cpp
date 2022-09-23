#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(char *input)
{
	this->detectType(input);
}

Converter::Converter(const Converter &other)
{
	*this = other;
}

Converter::~Converter() {}

Converter	&Converter::operator=(const Converter &other)
{
	if (this != &other)
	{

	}
	return (*this);
}

int	Converter::detectType(char *input)
{
	
	return (CHAR_TYPE);
}

	char	Converter::getChar(void) const {return (this->_char_literal);}
	int		Converter::getInt(void) const {return (this->_int_literal);}
	float	Converter::getFloat(void) const {return (this->_float_literal);}
	double	Converter::getDouble(void) const {return (this->_double_literal);}

