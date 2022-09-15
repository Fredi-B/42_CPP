#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
public:
	Character(void);
	Character(const Character &other);
	Character(std::string name);
	~Character(void);

	Character	&operator=(const Character &other);

	std::string const	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	void	empty_floor(void);
	void	empty_inventory(void);



private:
	std::string	name;
	AMateria	*inventory[4];
	AMateria	*floor[1000];
};

#endif
