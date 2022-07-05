#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:

		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string	getType(void);
		void				setType(std::string new_type);

	private:

		std::string	type;
};



#endif