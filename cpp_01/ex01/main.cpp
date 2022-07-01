#include "Zombie.hpp"

int	main(void)
{
	int	size_of_horde = 4;
	Zombie	*zombie_horde = Zombie::zombieHorde(size_of_horde, "Foo");
	
	if (zombie_horde == NULL)
		return (1);
	for (int i = 0; i < size_of_horde; i++)
		zombie_horde[i].announce();
	delete [] zombie_horde;
	return (0);
}
