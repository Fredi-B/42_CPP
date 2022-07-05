#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_type) : name(name), weapon(weapon_type) {};

HumanA::~HumanA(void) { }

Weapon	HumanA::get_weapon(void) {return (this->weapon);}

std::string	HumanA::get_name(void) {return (this->name);}

void	HumanA::attack(void)
{
	Weapon	weapon = HumanA::get_weapon();
	std::string type_of_weapon = weapon.getType();

	std::cout << HumanA::get_name() << " attacks with their " << type_of_weapon << std::endl;
}
