#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "Dog copy constructed" << std::endl;
	this->brain = NULL;
	*this = other;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructed" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wauu" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}

void	Dog::setIdea(std::string idea, unsigned int i)
{
	if (i > 0 && i <= 100)
		this->brain->ideas[i - 1] = idea;
	else
		std::cout << "too sophisticated" << std::endl;
}

std::string	Dog::getIdea(unsigned int i) const
{
	if (i <= 100)
		return (this->brain->ideas[i - 1]);
	else
		return ("yawning void");
}
