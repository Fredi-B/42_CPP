#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap constructed" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap::ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap_Copy constructed" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructed" << std::endl;
}
/* --------------------------------------------------------------------------------- */
ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getEnergyPoints();
		this->attack_damage = other.getAttackDamage();
	}
	return (*this);
}
/* `````````````````````````````````````````````````````````````````````````````````` */
void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " 
		<< target << ", causing " << this->getAttackDamage() << " points of damage!" 
		<< std::endl;
		this->setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << this->getName() << " can't attack! Peace " << target << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
