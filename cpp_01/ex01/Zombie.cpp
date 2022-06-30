#include "Zombie.hpp"

Zombie::Zombie(void) { }

Zombie::~Zombie(void)
{
	std::cout << get_name() << " got destroyed" << std::endl;
	return ;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	return ;
}

std::string	Zombie::get_name(void) const {return (this->name);}


void	Zombie::announce(void)
{
	std::cout << get_name()
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
