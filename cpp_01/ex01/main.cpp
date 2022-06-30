#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_horde = Zombie::zombieHorde(10, "Foo");
	
	delete [] zombie_horde;
	return (0);
}
