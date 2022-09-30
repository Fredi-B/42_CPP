#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(char *input) : _input(input)
{
	this->_input_type = this->detectType();
	this->convertType();
	this->printTypes();
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

void	Converter::convertType(void)
{
	if (this->_input_type == 0)
		convertFromChar();
	else if (this->_input_type == 1)
		convertFromInt();
	else if (this->_input_type == 2)
		convertFromFloat();
	else if (this->_input_type == 3)
		convertFromDouble();
}

void	Converter::convertFromChar(void)
{
	this->_char_literal = static_cast<char>(this->_input[0]);
	this->_int_literal = static_cast<int>(this->_char_literal);
	this->_float_literal = static_cast<float>(this->_char_literal);
	this->_double_literal = static_cast<double>(this->_char_literal);
}

void	Converter::convertFromInt(void)
{
	this->_int_literal = std::atoi(this->_input.c_str());
	this->_char_literal = static_cast<int>(this->_int_literal);
	this->_float_literal = static_cast<float>(this->_int_literal);
	this->_double_literal = static_cast<double>(this->_int_literal);
}

void	Converter::convertFromFloat(void)
{
	this->_float_literal = std::atof(this->_input.c_str());
	this->_char_literal = static_cast<int>(this->_float_literal);
	this->_int_literal = static_cast<float>(this->_float_literal);
	this->_double_literal = static_cast<double>(this->_float_literal);
}

void	Converter::convertFromDouble(void)
{
	this->_double_literal = std::atof(this->_input.c_str());
	this->_char_literal = static_cast<int>(this->_double_literal);
	this->_int_literal = static_cast<float>(this->_double_literal);
	this->_float_literal = static_cast<double>(this->_double_literal);
}

int	Converter::detectType(void)
{
	if (this->_input.length() < 1)
		throw Converter::NotAScalarTypeException();
	if (this->isInt() == true)
		return (INT_TYPE);
	else if (this->isDouble() == true)
		return (DOUBLE_TYPE);
	else if (this->isFloat() == true)
		return (FLOAT_TYPE);
	else if (this->isChar() == true)
		return (CHAR_TYPE);
	else
		throw Converter::NotAScalarTypeException();
}

bool	Converter::isInt(void)
{
	bool	return_value;

	if (this->_input.find_first_not_of("-+0123456789") == this->_input.npos)
	{
		if (this->_input.length() > 1)
		{
			if ((this->_input.find_first_of("-", 1) == this->_input.npos) \
			&& (this->_input.find_first_of("+", 1) == this->_input.npos))
				return_value = true;
			else
				return_value = false;
		}
		else if (this->_input.find_first_not_of("0123456789") == this->_input.npos)
			return_value = true;
		else
			return_value = false;
	}
	else
		return_value = false;
	return (return_value);
}

bool	Converter::isDouble(void)
{
	bool	return_value;

	if ((this->_input.find_first_not_of("-+0123456789.") == this->_input.npos \
	&& (this->_input.length() > 1 && ((this->_input.find_first_of("-", 1) == this->_input.npos) && (this->_input.find_first_of("+", 1) == this->_input.npos))) \
	&& this->_input.find(".", this->_input.length() - 1) == this->_input.npos \
	&& this->_input.find(".", this->_input.find(".") + 1) == this->_input.npos) \
	|| (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan"))
		return_value = true;
	else
		return_value = false;
	return (return_value);
}

bool	Converter::isFloat(void)
{
	bool	return_value;

	if ((this->_input.find_first_not_of("-+0123456789.f") == this->_input.npos \
	&& (this->_input.length() > 1 && ((this->_input.find_first_of("-", 1) == this->_input.npos) && (this->_input.find_first_of("+", 1) == this->_input.npos))) \
	&& this->_input.find(".", this->_input.length() - 2) == this->_input.npos && this->_input.find("f", this->_input.length() - 1) == this->_input.length() - 1 \
	&& this->_input.find_first_of(".") != this->_input.npos \
	&& this->_input.find(".", this->_input.find(".") + 1) == this->_input.npos \
	&& this->_input.find("f", this->_input.find("f") + 1) == this->_input.npos) \
	|| (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf"))
		return_value = true;
	else
		return_value = false;
	return (return_value);
}

bool	Converter::isChar(void)
{
	bool	return_value;

	if (this->_input.length() != 1)
		return_value = false;
	else
		return_value = true;
	return	(return_value);
}

void	Converter::printTypes(void)
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void	Converter::printChar(void)
{
	if (std::isprint(static_cast<unsigned char>(this->_char_literal)) == 0)
	{
		if (this->_input == "nan" || this->_input == "nanf" \
		|| this->_input == "+inf" || this->_input == "+inff" \
		|| this->_input == "-inf" || this->_input == "-inff")
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << this->_char_literal << std::endl;
}

void	Converter::printInt(void)
{
	if (this->_input == "nan" || this->_input == "nanf" \
	|| this->_input == "+inf" || this->_input == "+inff" \
	|| this->_input == "-inf" || this->_input == "-inff" \
	|| atof(this->_input.c_str()) < INT32_MIN || atof(this->_input.c_str()) > INT32_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->_int_literal << std::endl;
}

void	Converter::printFloat(void)
{
	if (this->_input == "nan" || this->_input == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (this->_input == "+inf" || this->_input == "+inff")
		std::cout << "float: +inff" << std::endl;
	else if(this->_input == "-inf" || this->_input == "-inff")
		std::cout << "float: -inff" << std::endl;
	else if (atof(this->_input.c_str()) < INT32_MIN || atof(this->_input.c_str()) > INT32_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: " << this->_float_literal;
		if ((this->_input_type == 0 || this->_input_type == 1) \
		|| this->_input.find_first_not_of("0f", this->_input.find(".") + 1) == this->_input.npos)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

void	Converter::printDouble(void)
{
	if (this->_input == "nan" || this->_input == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (this->_input == "+inf" || this->_input == "+inff")
		std::cout << "double: +inf" << std::endl;
	else if(this->_input == "-inf" || this->_input == "-inff")
		std::cout << "double: -inf" << std::endl;
	else if (atof(this->_input.c_str()) < INT32_MIN || atof(this->_input.c_str()) > INT32_MAX)
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << "double: " << this->_double_literal;
		if (this->_input_type == 0 || this->_input_type == 1 \
		|| this->_input.find_first_not_of("0f", this->_input.find(".") + 1) == this->_input.npos)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

	char	Converter::getChar(void) const {return (this->_char_literal);}
	int		Converter::getInt(void) const {return (this->_int_literal);}
	float	Converter::getFloat(void) const {return (this->_float_literal);}
	double	Converter::getDouble(void) const {return (this->_double_literal);}

const char	*Converter::NotAScalarTypeException::what() const throw()
{
	return ("not a type we are looking for");
}
