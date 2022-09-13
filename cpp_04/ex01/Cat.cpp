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

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}

void	Cat::setIdea(std::string idea, unsigned int i)
{
	if (i > 0 && i <= 100)
		this->brain->ideas[i - 1] = idea;
	else
		std::cout << "too sophisticated" << std::endl;
}

std::string	Cat::getIdea(unsigned int i) const
{
	if (i <= 100)
		return (this->brain->ideas[i - 1]);
	else
		return ("yawning void");
}
