#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) { };

HumanB::~HumanB(void) { };

std::string	HumanB::get_name(void) {return (this->name);}

Weapon	*HumanB::get_weapon(void) {return (this->weapon);}

std::string	HumanB::get_type_of_weapon(void)
{
	Weapon	*weapon = HumanB::get_weapon();

	return (weapon->getType());
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << HumanB::get_name() << " attacks with their " << HumanB::get_type_of_weapon() << std::endl;

}
