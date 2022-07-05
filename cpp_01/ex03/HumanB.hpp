#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:

		HumanB(std::string name);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon &weapon);

	private:

		std::string	name;
		Weapon		*weapon;

		std::string	get_name(void);
		Weapon		*get_weapon(void);
		std::string	get_type_of_weapon(void);
};

#endif