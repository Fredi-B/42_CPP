#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "Dog copy constructed" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructed" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wauu" << std::endl;
}
