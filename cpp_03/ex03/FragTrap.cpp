#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("noname", 100, 100, 30)
{
	std::cout << "FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap::ClapTrap(other)
{
	std::cout << "FragTrap_Copy constructed" << std::endl;
	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructed" << std::endl;
}
/* --------------------------------------------------------------------------------- */
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}
/* `````````````````````````````````````````````````````````````````````````````````` */
void	FragTrap::highFivesGuys(void)
{
	std::cout << "positive high fives request!" << std::endl;
}
