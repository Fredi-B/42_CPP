#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
public:
	Data();
	Data(const Data &other);
	~Data();

	Data	&operator=(const Data &other);

	std::string	name;
	int			age;
};

#endif
