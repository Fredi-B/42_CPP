#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dino_trap("dino");
	dino_trap.whoAmI();
	std::cout << dino_trap.getHitPoints() << std::endl;
	std::cout << dino_trap.getEnergyPoints() << std::endl;
	std::cout << dino_trap.getAttackDamage() << std::endl;
}
