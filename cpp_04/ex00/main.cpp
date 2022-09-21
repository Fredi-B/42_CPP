#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "---------constructor-----------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "---------correct sounds-----------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "---------destructor-----------" << std::endl;
	delete j;
	delete i;
	delete meta;

	std::cout << std::endl << "---------constructor-----------" << std::endl;
	const WrongAnimal* metawrong = new WrongAnimal();
	const WrongAnimal* fakecat = new WrongCat();

	std::cout << std::endl << "---------wrong sounds-----------" << std::endl;
	std::cout << metawrong->getType() << std::endl;
	metawrong->makeSound();
	std::cout << fakecat->getType() << std::endl;
	fakecat->makeSound();

	std::cout << std::endl << "---------destructor-----------" << std::endl;
	delete fakecat;
	delete metawrong;
}
