#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon &weapon_type);
		~HumanA(void);

		void	attack(void);

	private:

		std::string	name;
		Weapon		&weapon;
		
		std::string	get_name(void);
		Weapon		get_weapon(void);
};

#endif
