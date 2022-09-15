#include "AMateria.hpp"

AMateria::AMateria(void) : type("AMateria")
{
	// std::cout << "AMateria constructed" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	// std::cout << "AMateria of type " << this->type << " constructed" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	// std::cout << "Copy of AMateria constructed" << std::endl;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructed" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string const	&AMateria::getType(void) const {return (this->type);}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* wonderful things happen to " << target.getName() << " *" << std::endl;
}
