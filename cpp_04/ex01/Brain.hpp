#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
public:
	Brain(void);
	Brain(const Brain &other);
	~Brain(void);

	Brain	&operator=(const Brain &other);

	std::string	ideas[100];
};

#endif