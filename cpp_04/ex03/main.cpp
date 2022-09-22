#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// IMateriaSource	*src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// AMateria	*tmp;
	// tmp = src->createMateria("cure");
	// AMateria	*tmp2;
	// tmp2 = src->createMateria("ice");

	// Character	*bob = new Character("bob");
	// bob->equip(tmp);
	// bob->equip(tmp2);

	// Character	*jim = new Character("jim");
	// *jim = *bob;

	// jim->use(0, *bob);
	// bob->use(0, *jim);
	// bob->use(1, *jim);

	// delete src;
	// delete bob;
	// delete jim;
	
	return 0;
}
