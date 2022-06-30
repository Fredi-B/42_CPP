#include "Zombie.hpp"

Zombie	*Zombie::newZombie(std::string name)
{
	Zombie*	new_zombie = new Zombie();

	new_zombie->set_name(name);
	return (new_zombie);
}
