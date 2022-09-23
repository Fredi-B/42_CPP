#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: program takes as parameter one string only" << std::endl;
		return (1);
	}
	try
	{
		Converter convertPro(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
