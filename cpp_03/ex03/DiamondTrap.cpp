#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << "DiamondTrap constructed" << std::endl;
	{
		this->name = "noname";
		this->hit_points = FragTrap::hit_points;
		this->energy_points = ScavTrap::energy_points;
		this->attack_damage = FragTrap::attack_damage;
	}
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << name << " constructed" << std::endl;
	{
		this->name = name;
		this->hit_points = FragTrap::hit_points;
		this->energy_points = ScavTrap::energy_points;
		this->attack_damage = FragTrap::attack_damage;
	}
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap_Copy constructed" << std::endl;
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

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Name: " << this->name << " | Base name: " << this->ClapTrap::name << std::endl;
	std::cout << this->ScavTrap::attack_damage << std::endl;
	std::cout << this->ClapTrap::attack_damage << std::endl;
	std::cout << this->FragTrap::attack_damage << std::endl;
	std::cout << this->DiamondTrap::attack_damage << std::endl;

}