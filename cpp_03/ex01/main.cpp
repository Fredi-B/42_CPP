#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap stone_trap("stoney");
	std::cout << stone_trap.getHitPoints() << std::endl;
	stone_trap.beRepaired(10);
	ScavTrap rock_trap(stone_trap);
	std::cout << rock_trap.getHitPoints() << std::endl;
	std::cout << rock_trap.getName() << std::endl;
	stone_trap.attack("paper");
	stone_trap.guardGate();
}
