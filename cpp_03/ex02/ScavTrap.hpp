#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &other);
	ScavTrap(std::string name);
	~ScavTrap(void);
/* --------------------------------------------------------------------------------- */
	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif
