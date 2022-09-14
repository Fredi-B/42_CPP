#include "Character.hpp"

Character::Character(void) : name("Character")
{
	std::cout << "Character materia constructed" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		this->floor[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Character materia constructed" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		this->floor[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout << "Copy of Character materia constructed" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
		{
			delete inventory[i];
			this->inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		if (this->floor[i] != NULL)
		{
			delete floor[i];
			this->floor[i] = NULL;
		}
	}
	std::cout << "Character materia destructed" << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
			{
				delete inventory[i];
				this->inventory[i] = NULL;
			}
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
		}
		for (int i = 0; i < 1000; i++)
		{
			if (this->floor[i] != NULL)
			{
				delete floor[i];
				this->floor[i] = NULL;
			}
			if (other.inventory[i] != NULL)
				this->floor[i] = other.floor[i]->clone();
		}
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << this->getName() << " put " << m->getType() << " in invetory slot no. " << i << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (this->inventory[idx] != NULL)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (this->floor[i] == NULL)
			{
				this->floor[i] = this->inventory[idx];
				std::cout << this->name << " left " << this->inventory[idx]->getType() << " on the floor" << std::endl;
				this->inventory[idx] = NULL;
				return ;
			}
		}
	}
	std::cout << "floor is full. stop it" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}