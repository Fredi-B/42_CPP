#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int	main(void)
// {
// 	Weapon	axe = Weapon("axe");
// 	HumanA	bob("Bob", axe);
// 	HumanB	jim("Jim");

// 	bob.attack();
// 	axe.setType("blub");
// 	bob.attack();

// 	jim.setWeapon(axe);
// 	jim.attack();
// 	axe.setType("bla");
// 	jim.attack();
// 	system("leaks weapon");

// }

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}