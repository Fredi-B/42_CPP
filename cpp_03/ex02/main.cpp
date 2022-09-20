#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "---------constructor----------" << std::endl;
	FragTrap frost_trap("frosty");
	FragTrap frosty_frost(frost_trap);

	std::cout << std::endl << "---------copy value----------" << std::endl;
	std::cout << "frost_trap attack damage: " << frost_trap.getAttackDamage() << std::endl;
	std::cout << "frosty_frost attack damage: " << frosty_frost.getAttackDamage() << std::endl;

	std::cout << std::endl << "---------frag fct----------" << std::endl;
	frosty_frost.highFivesGuys();

	std::cout << std::endl << "---------frag attack----------" << std::endl;
	frost_trap.attack("tree");

	std::cout << std::endl << "---------destructor----------" << std::endl;
}
