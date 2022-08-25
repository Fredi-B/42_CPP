#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include <iostream>
/* # include "ClapTrap.hpp" */
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : /* virtual public ClapTrap, (hat alf net und alles andersda) */ virtual public ScavTrap, virtual public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
/* --------------------------------------------------------------------------------- */
	void	whoAmI();
	void	attack(const std::string &target);
/*====================================================================================== */
private:
	std::string	name;
};

#endif
