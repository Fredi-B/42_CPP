#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "constructor" << std::endl;
	DiamondTrap dino_trap("dino");

	std::cout << std::endl << "who am I?" << std::endl;
	dino_trap.whoAmI();

	std::cout << std::endl << "values and attack" << std::endl;
	std::cout << dino_trap.getHitPoints() << std::endl;
	std::cout << dino_trap.getEnergyPoints() << std::endl;
	std::cout << dino_trap.getAttackDamage() << std::endl;
	dino_trap.attack("comet");

	std::cout << std::endl << "destructor" << std::endl;
}
