#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("noname"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage)
: name(name), hit_points(hit_points),energy_points(energy_points), attack_damage(attack_damage)
{
	std::cout << "Problem constructor called" << std::endl;
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
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}
/* `````````````````````````````````````````````````````````````````````````````````` */
void	ClapTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " 
		<< target << ", causing " << this->attack_damage << " points of damage!" 
		<< std::endl;
		this->energy_points--;
	}
	else
	{
		std::cout << this->name << " can't attack " << target << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > UINT32_MAX)
	{
		std::cout << "ClapTrap takes no damage no no" << std::endl;
	}
	else if (this->hit_points > amount)
	{
		this->hit_points -= amount;
		std::cout << "ClapTrap " << this->name << " got attacked and has " 
		<< this->hit_points << " hit points left!" << std::endl;
	}
	else
	{
		this->hit_points = 0;
		std::cout << "ClapTrap " << this->name << " got attacked and has died!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0 && amount > 0 && (long) amount + this->hit_points < UINT32_MAX)
	{
		this->hit_points += amount;
		std::cout << "ClapTrap " << this->name << " repairs itself by "
		<< amount << "!" << std::endl; 
		this->energy_points--;
	}
	else
	{
		std::cout << this->name << " can't repair itself!" << std::endl;
	}
}

/* `````````````````````````````````````````````````````````````````````````````````` */
void	ClapTrap::setName(std::string _name) {this->name = _name;}
void	ClapTrap::setHitPoints(unsigned int amount) {this->hit_points = amount;}
void	ClapTrap::setEnergyPoints(unsigned int amount) {this->energy_points = amount;}
void	ClapTrap::setAttackDamage(unsigned int amount) {this->attack_damage = amount;}
std::string		ClapTrap::getName(void) const {return (this->name);}
unsigned int	ClapTrap::getHitPoints(void) const {return (this->hit_points);}
unsigned int	ClapTrap::getEnergyPoints(void) const {return (this->energy_points);}
unsigned int	ClapTrap::getAttackDamage(void) const {return (this->attack_damage);}

std::ostream &operator<<(std::ostream &o, const ClapTrap &ct)
{
    o << ct.getName() << "\nhit points: " << ct.getHitPoints()
        << "\nenergy points: " << ct.getEnergyPoints()
        << "\nattack damage: " << ct.getAttackDamage()
        << "\n";
    return (o);
}