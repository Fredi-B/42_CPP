#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("noname"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
/* --------------------------------------------------------------------------------- */
ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
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
void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " 
		<< target << ", causing " << this->getAttackDamage() << " points of damage!" 
		<< std::endl;
		this->energy_points--;
	}
	else
	{
		std::cout << this->getName() << " can't attack " << target << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() > amount)
	{
		this->setHitPoints(this->getHitPoints() - amount);
		std::cout << "ClapTrap " << this->getName() << " got attacked and has " 
		<< this->getHitPoints() << " hit points left!" << std::endl;
	}
	else
	{
		this->setHitPoints(0);
		std::cout << "ClapTrap " << this->getName() << " got attacked and has died!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << "ClapTrap " << this->getName() << " repairs itself by "
		<< amount << "!" << std::endl; 
		this->energy_points--;
	}
	else
	{
		std::cout << this->getName() << " can't repair itself!" << std::endl;
	}
}

/* `````````````````````````````````````````````````````````````````````````````````` */
void	ClapTrap::setName(std::string name) {this->name = name;}
void	ClapTrap::setHitPoints(unsigned int amount) {this->hit_points = amount;}
void	ClapTrap::setEnergyPoints(unsigned int amount) {this->energy_points = amount;}
void	ClapTrap::setAttackDamage(unsigned int amount) {this->attack_damage = amount;}
std::string		ClapTrap::getName(void) const {return (this->name);}
unsigned int	ClapTrap::getHitPoints(void) const {return (this->hit_points);}
unsigned int	ClapTrap::getEnergyPoints(void) const {return (this->energy_points);}
unsigned int	ClapTrap::getAttackDamage(void) const {return (this->attack_damage);}
