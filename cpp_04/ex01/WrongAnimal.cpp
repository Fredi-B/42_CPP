#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimaltest";
	this->sound = "what?";
	std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructed" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructed" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "wrong of silence" << std::endl;
}

std::string	WrongAnimal::getType(void) const {return (this->type);}
