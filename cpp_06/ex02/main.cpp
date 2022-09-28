#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	Base	*random_pointer = NULL;

	random_pointer = generate();
	if (random_pointer != NULL)
	{
		identify(random_pointer);
		identify(*random_pointer);
		delete random_pointer;
	}
	return (0);
}

Base	*generate(void)
{
	switch (int i = arc4random() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer: Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer: Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer: Type is C" << std::endl;
	else
		std::cout << "pointer: Type is unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "reference: Type is A" << std::endl;
	}
	catch(const std::bad_cast& bc)
	{
	}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "reference: Type is B" << std::endl;
	}
	catch(const std::bad_cast& bc)
	{
	}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "reference: Type is C" << std::endl;
	}
	catch(const std::bad_cast& bc)
	{
	}
}
