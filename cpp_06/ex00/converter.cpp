#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(char *input) : _input(input)
{
	this->_input_type = this->detectType();
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
		this->_input = other._input;
		this->_input_type = other._input_type;
		this->_char_literal = other._char_literal;
		this->_int_literal = other._int_literal;
		this->_float_literal = other._float_literal;
		this->_double_literal = other._double_literal;
	}
	return (*this);
}

int	Converter::detectType()
{
	if (this->isInt() == true)
		return (INT_TYPE);
	// else if (this->isFloat() == true)
	// 	return (FLOAT_TYPE);
	// else if (this->isDouble() == true)
	// 	return (DOUBLE_TYPE);
	// else if (this->isChar() == true)
	// 	return (CHAR_TYPE);
	else
		throw Converter::NotAScalarTypeException();
}

// bool	Converter::isChar(void)
// {
// 	bool	return_value;

// 	return_value = false;
// 	if (this->_input.length() != 1)
// 		return_value = false;
// 	return	(return_value);
// }

	char	Converter::getChar(void) const {return (this->_char_literal);}
	int		Converter::getInt(void) const {return (this->_int_literal);}
	float	Converter::getFloat(void) const {return (this->_float_literal);}
	double	Converter::getDouble(void) const {return (this->_double_literal);}

const char	*Converter::NotAScalarTypeException::what() const throw()
{
	return ("not a type we are looking for");
}
