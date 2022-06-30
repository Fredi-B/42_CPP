#include "Zombie.hpp"

int	main(void)
{
	Zombie	*new_zombie = Zombie::newZombie("Foo");

	new_zombie->announce();
	delete new_zombie;
	Zombie::randomChump("Bar");
	return (0);
}
