#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "Cat copy constructed" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructed" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
