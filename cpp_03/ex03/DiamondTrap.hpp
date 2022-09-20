#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
/* --------------------------------------------------------------------------------- */
DiamondTrap	&operator=(const DiamondTrap &other);
/* `````````````````````````````````````````````````````````````````````````````````` */
	void	whoAmI(void);
/*====================================================================================== */
private:
	std::string	name;
};

#endif
