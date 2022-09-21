#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// pure Animal instantiation does not work because it's an abstract class
	// const Animal    *meta = new Animal();

	std::cout << std::endl << "---------create dog----------" << std::endl;
	Dog	*doggo = new Dog();

	std::cout << std::endl << "-------fill animal array--------" << std::endl;
	Animal	*animals[2];
	animals[0] = doggo;
	animals[1] = new Cat();

	std::cout << std::endl << "--------delete animal array------" << std::endl;
	for (int i = 0; i < 2; i++)
		delete animals[i];

	// system("leaks abstract");
	return (0);
}
