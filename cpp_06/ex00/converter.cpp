	std::cout << "iput_type: " << this->_input_type << std::endl;
	this->convertType();
	this->printTypes();
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
	else if (this->isChar() == true)
		return (CHAR_TYPE);
	if (this->_input.find_first_not_of("-+0123456789") == this->_input.npos)
	{
		if (this->_input.length() > 1)
		{
			if ((this->_input.find_first_of("-", 1) == this->_input.npos) \
			&& (this->_input.find_first_of("+", 1) == this->_input.npos))
		}
		else if (this->_input.find_first_not_of("0123456789") == this->_input.npos)
			return_value = true;
		else
			return_value = false;
	}
	else
		return_value = false;
	if ((this->_input.find_first_not_of("-+0123456789.") == this->_input.npos \
	&& this->_input.find(".", this->_input.length() - 1) == this->_input.npos \
	&& this->_input.find(".", this->_input.find(".") + 1) == this->_input.npos) \
	|| (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan"))
	if ((this->_input.find_first_not_of("-+0123456789.f") == this->_input.npos \
	&& this->_input.find_first_of(".") != this->_input.npos \
	&& this->_input.find(".", this->_input.find(".") + 1) == this->_input.npos \
	&& this->_input.find("f", this->_input.find("f") + 1) == this->_input.npos) \
	|| (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf"))
