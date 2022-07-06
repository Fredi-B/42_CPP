#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	customer;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	customer.complain(argv[1]);
	return (0);
}