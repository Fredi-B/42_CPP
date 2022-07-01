#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	if (N < 0)
		return (NULL);
	Zombie* zombie_horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie_horde[i].set_name(name);
	return (zombie_horde);
}
