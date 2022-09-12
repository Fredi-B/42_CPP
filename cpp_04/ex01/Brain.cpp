#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructed" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
