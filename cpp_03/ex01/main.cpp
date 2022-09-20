#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "---------constructor----------" << std::endl;
	ScavTrap stone_trap("stoney");

	std::cout << "stone_trap hit points: " << stone_trap.getHitPoints() << std::endl;
	stone_trap.beRepaired(10);

	std::cout << std::endl << "---------copy constructor----------" << std::endl;
	ScavTrap rock_trap(stone_trap);

	std::cout << std::endl << "---------copy values----------" << std::endl;
	std::cout << "rock_trap hit points: " << rock_trap.getHitPoints() << std::endl;
	std::cout << "rock_trap name: " << rock_trap.getName() << std::endl;
	
	std::cout << std::endl << "---------scav fcts----------" << std::endl;
	stone_trap.attack("paper");
	stone_trap.guardGate();

	std::cout << std::endl << "---------destructor----------" << std::endl;
}
