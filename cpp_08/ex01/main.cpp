#include "Span.hpp"

int	main(void)
{
	Span	sp(100);

	try
	{
		sp.addManyNumbers(1);

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}




	return (0);
}
