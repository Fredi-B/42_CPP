#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "---------pdf test: create i & j----------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl << "---------pdf test: delete i & j----------" << std::endl;
	delete j;
	delete i;

	std::cout << std::endl << "---------create dogs----------" << std::endl;
	Dog	*doggo = new Dog();
	Dog	*boggo = new Dog();

	std::cout << std::endl << "----print ideas before assignment----" << std::endl;
	doggo->setIdea("food", 1);
	doggo->setIdea("water", 2);
	std::cout << "Doggo's Idea 1: " << doggo->getIdea(1) << std::endl;
	std::cout << "Doggo's Idea 2: " << doggo->getIdea(2) << std::endl;
	std::cout << "Boggo's Idea 1: " << boggo->getIdea(1) << std::endl;
	std::cout << "Boggo's Idea 2: " << boggo->getIdea(2) << std::endl;

	std::cout << std::endl << "---- assign doggo to boggo----" << std::endl;
	*boggo = *doggo;

	std::cout << std::endl << "----print ideas after assignment----" << std::endl;
	std::cout << "Boggo's Idea 1: " << boggo->getIdea(1) << std::endl;
	std::cout << "Boggo's Idea 2: " << boggo->getIdea(2) << std::endl;

	std::cout << std::endl << "-------fill animal array--------" << std::endl;
	Animal	*animals[2];
	animals[0] = doggo;
	animals[1] = new Cat();

	std::cout << std::endl << "--------delete animal array------" << std::endl;
	for (int i = 0; i < 2; i++)
		delete animals[i];

	std::cout << std::endl << "-----------delete boggo----------" << std::endl;
	delete boggo;

	system("leaks brains");
	return (0);
}
