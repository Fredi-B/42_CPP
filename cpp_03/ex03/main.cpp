#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dino_trap("dino");
	dino_trap.whoAmI();
	ScavTrap scavi("scav");
	std::cout << scavi.getEnergyPoints() << std::endl;
/* 	std::cout << dino_trap.getHitPoints() << std::endl;
	std::cout << dino_trap.getEnergyPoints() << std::endl;
	std::cout << dino_trap.getAttackDamage() << std::endl;
	std::cout << dino_trap.ScavTrap::getEnergyPoints() << std::endl;
	dino_trap.setEnergyPoints(dino_trap.ScavTrap::getEnergyPoints());
	std::cout << "scav:" << dino_trap.ScavTrap::getEnergyPoints() << std::endl;
	std::cout << "dino" << dino_trap.getEnergyPoints() << std::endl;
 */
}
