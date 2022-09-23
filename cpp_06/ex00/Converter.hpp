#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

# define CHAR_TYPE 0
# define INT_TYPE 1
# define FLOAT_TYPE 2
# define DOUBLE_TYPE 3

class Converter
{
public:
	Converter();
	Converter(char *input);
	Converter(const Converter &other);
	~Converter();

	Converter	&operator=(const Converter &other);

	int	detectType(char *input);



	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

private:
	char	_char_literal;
	int		_int_literal;
	float	_float_literal;
	double	_double_literal;
};

#endif
