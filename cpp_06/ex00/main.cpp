#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: program takes as parameter one string only" << std::endl;
		return (1);
	}
	Converter convertPro(argv[1]);
	return (0);
}
