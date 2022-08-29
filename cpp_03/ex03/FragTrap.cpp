#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap constructed" << std::endl;

	this->name = "noname";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructed" << std::endl;

	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap::ClapTrap(other)
{
	std::cout << "FragTrap_Copy constructed" << std::endl;
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
void	FragTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->energy_points > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " 
		<< target << ", causing " << this->attack_damage << " points of damage!" 
		<< std::endl;
		this->energy_points--;
	}
	else
	{
		std::cout << this->name << " can't attack! Peace " << target << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "positive high fives request!" << std::endl;
}
