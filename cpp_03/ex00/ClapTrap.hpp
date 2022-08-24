#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);
	~ClapTrap(void);
/* --------------------------------------------------------------------------------- */
	ClapTrap	&operator=(const ClapTrap &other);
/* `````````````````````````````````````````````````````````````````````````````````` */
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amout);
	void	beRepaired(unsigned int amout);
/* `````````````````````````````````````````````````````````````````````````````````` */
	void			setName(std::string name);
	void			setHitPoints(unsigned int amount);
	void			setEnergyPoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

/*====================================================================================== */
private:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
};

#endif
