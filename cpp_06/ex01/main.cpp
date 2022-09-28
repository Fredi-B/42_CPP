#include "Data.hpp"

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

int	main(void)
{
	Data *a = new Data;
	Data *b;
	uintptr_t ptr;

	std::cout << std::endl << "------a->age----" << std::endl;
	std::cout << a->age << std::endl;

	std::cout << std::endl << "------ptr----" << std::endl;
	ptr = serialize(a);
	std::cout << ptr << std::endl;
	
	std::cout << std::endl << "------b->age----" << std::endl;
	b = deserialize(ptr);
	std::cout << b->age << std::endl;
	delete a;
	return (0);
}

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
