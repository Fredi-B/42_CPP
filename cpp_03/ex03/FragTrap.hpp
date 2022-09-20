#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const FragTrap &other);
	FragTrap(std::string name);
	~FragTrap(void);
/* --------------------------------------------------------------------------------- */
	FragTrap	&operator=(const FragTrap &other);
/* `````````````````````````````````````````````````````````````````````````````````` */
	void	highFivesGuys(void);
};

#endif
