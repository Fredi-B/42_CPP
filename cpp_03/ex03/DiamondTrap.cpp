#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("noname_clap_name", 100, 50, 30)
{
	std::cout << "DiamondTrap constructed" << std::endl;
	this->name = "noname";
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name", 100, 50, 30)
{
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
	this->name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap_Copy constructed" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructed" << std::endl;
}
/* --------------------------------------------------------------------------------- */
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if(this != &other)
	{
		this->ClapTrap::name = other.name + "_clap_name";
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}
/* `````````````````````````````````````````````````````````````````````````````````` */

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Name: " << this->name << " | Base name: " << this->ClapTrap::name << std::endl;
}