#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frost_trap("frosty");
	FragTrap frosty_frost(frost_trap);
	std::cout << frosty_frost.getAttackDamage() << std::endl;
	frosty_frost.highFivesGuys();
}
