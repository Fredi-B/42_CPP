#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie	random_chump;

	random_chump.set_name(name);
	random_chump.announce();
}
