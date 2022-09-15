#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure materia constructed" << std::endl;
}

Cure::Cure(const Cure &other)
{
	*this = other;
	// std::cout << "Copy of Cure materia constructed" << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "Cure materia destructed" << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
