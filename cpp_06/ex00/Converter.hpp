#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <exception>

# define CHAR_TYPE 0
# define INT_TYPE 1
# define FLOAT_TYPE 2
# define DOUBLE_TYPE 3
# define ERROR_TYPE 4

class Converter
{
public:
	Converter();
	Converter(char *input);
	Converter(const Converter &other);
	~Converter();

	Converter	&operator=(const Converter &other);

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

private:
	std::string	_input;
	int			_input_type;
	char		_char_literal;
	int			_int_literal;
	float		_float_literal;
	double		_double_literal;

	int		detectType(void);
	bool	isChar(void);
	bool	isInt(void);
	bool	isFloat(void);
	bool	isDouble(void);

	class NotAScalarTypeException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
};

#endif
