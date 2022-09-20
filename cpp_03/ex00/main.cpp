#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ctrap;
	ClapTrap ftrap("fire_t");

	std::cout << std::endl << "----attack--------" << std::endl;
	ftrap.attack("evil");
	ftrap.setEnergyPoints(0);
	ftrap.attack("good");

	std::cout << std::endl << "----repair--------" << std::endl;
	ftrap.setEnergyPoints(10);
	std::cout << ftrap.getHitPoints() << std::endl;
	ftrap.beRepaired(10);
	std::cout << ftrap.getHitPoints() << std::endl;
	ftrap.setEnergyPoints(0);
	ftrap.beRepaired(10);
	ftrap.takeDamage(10);
	ftrap.setEnergyPoints(10);

	std::cout << std::endl << "----copy--------" << std::endl;
	ClapTrap copy_trap(ftrap);
	copy_trap.beRepaired(10);
	copy_trap.takeDamage(10);
	copy_trap.takeDamage(10);
	ftrap.takeDamage(10);

	std::cout << std::endl << "----destructor--------" << std::endl;
	return (0);
}