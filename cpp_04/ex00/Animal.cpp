#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructed" << std::endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructed" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "sound of silence" << std::endl;
}

std::string	Animal::getType(void) const {return (this->type);}
