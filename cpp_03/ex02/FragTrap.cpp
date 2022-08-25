#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap constructed" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	std::cout << "FragTrap " << name << " constructed" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
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

void	FragTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "FragTrap " << this->getName() << " attacks " 
		<< target << ", causing " << this->getAttackDamage() << " points of damage!" 
		<< std::endl;
		this->setEnergyPoints(getEnergyPoints() - 1);
	}
	else
	{
		std::cout << this->getName() << " can't attack! Peace " << target << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "positive high fives request!" << std::endl;
}
