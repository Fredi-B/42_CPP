#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice materia constructed" << std::endl;
}

Ice::Ice(const Ice &other)
{
	*this = other;
	// std::cout << "Copy of Ice materia constructed" << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "Ice materia destructed" << std::endl;
}

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
