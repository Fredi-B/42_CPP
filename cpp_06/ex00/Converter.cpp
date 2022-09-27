#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(char *input) : _input(input)
{
	this->_input_type = this->detectType();
	std::cout << this->_input_type << std::endl;
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
	if (this->_input.length() < 1)
		throw Converter::NotAScalarTypeException();
	if (this->isInt() == true)
		return (INT_TYPE);
	else if (this->isDouble() == true)
		return (DOUBLE_TYPE);
	else if (this->isFloat() == true)
		return (FLOAT_TYPE);
	// else if (this->isChar() == true)
	// 	return (CHAR_TYPE);
	else
		throw Converter::NotAScalarTypeException();
}

bool	Converter::isInt(void)
{
	bool	return_value;

	if (this->_input.find_first_not_of("-+0123456789") == this->_input.npos \
	&& (this->_input.length() > 1 && ((this->_input.find_first_of("-", 1) == this->_input.npos) && (this->_input.find_first_of("+", 1) == this->_input.npos))))
		return_value = true;
	else
		return_value = false;
	return (return_value);
}

bool	Converter::isDouble(void)
{
	bool	return_value;

	if (this->_input.find_first_not_of("-+0123456789.") == this->_input.npos \
	&& (this->_input.length() > 1 && ((this->_input.find_first_of("-", 1) == this->_input.npos) && (this->_input.find_first_of("+", 1) == this->_input.npos))) \
	&& this->_input.find(".", this->_input.length() - 1) == this->_input.npos)
		return_value = true;
	else
		return_value = false;
	return (return_value);
}

bool	Converter::isFloat(void)
{
	bool	return_value;

	if (this->_input.find_first_not_of("-+0123456789.f") == this->_input.npos \
	&& (this->_input.length() > 1 && ((this->_input.find_first_of("-", 1) == this->_input.npos) && (this->_input.find_first_of("+", 1) == this->_input.npos))) \
	&& this->_input.find(".", this->_input.length() - 2) == this->_input.npos && this->_input.find("f", this->_input.length() - 1) == this->_input.length() - 1 \
	&& this->_input.find_first_of(".") != this->_input.npos)
		return_value = true;
	else
		return_value = false;
	return (return_value);
}

bool	Converter::isChar(void)
{
	bool	return_value;
	char	c;

	if (this->_input.length() != 1)
		return_value = false;
	else
		return_value = true;
	return	(return_value);
}

	char	Converter::getChar(void) const {return (this->_char_literal);}
	int		Converter::getInt(void) const {return (this->_int_literal);}
	float	Converter::getFloat(void) const {return (this->_float_literal);}
	double	Converter::getDouble(void) const {return (this->_double_literal);}

const char	*Converter::NotAScalarTypeException::what() const throw()
{
	return ("not a type we are looking for");
}
