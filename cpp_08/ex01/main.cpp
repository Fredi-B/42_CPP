#include "Span.hpp"

int	main(void)
{

	try
	{
		std::cout << std::endl << "-------- many numbers test --------" << std::endl;
		Span	sp1(10000);

		sp1.addManyNumbers(10000);

		std::cout << sp1.longestSpan() << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;

		std::cout << std::endl << "-------- pdf test --------" << std::endl;
		Span	sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
