#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "-----------------" << std::endl;
	try
	{
		Bureaucrat pia("Pia", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat peter("Peter", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat pia("Pia", 1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat peter("Peter", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}

	std::cout << "-------Pia increments----------" << std::endl;
	try
	{
		Bureaucrat pia("Pia", 2);
		std::cout << pia << std::endl;
		pia.increment();
		std::cout << pia << std::endl;
		pia.increment();
		std::cout << pia << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}

	std::cout << "-------Peter decrements----------" << std::endl;
	try
	{
		Bureaucrat peter("Peter", 149);
		std::cout << peter << std::endl;
		peter.decrement();
		std::cout << peter << std::endl;
		peter.decrement();
		std::cout << peter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}
	return (0);
}
