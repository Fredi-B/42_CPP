#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const FragTrap &other);
	FragTrap(std::string name);
	~FragTrap(void);
/* --------------------------------------------------------------------------------- */
	void	attack(const std::string &target);
	void	highFivesGuys(void);
};

#endif
