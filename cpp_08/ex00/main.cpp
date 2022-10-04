#include "easyfind.hpp"

int	main(void)
{
	std::cout << std::endl << "--------- list -----------" << std::endl;
	std::cout << "--------- jup -----------" << std::endl;

	int				i = 0;
	std::list<int>	l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	try
	{
		i = easyfind(l, 1);
		std::cout << "Found in list: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in list test: " << e.what() << std::endl;
	}

	std::cout << std::endl << "--------- no -----------" << std::endl;

	i = 0;
	try
	{
		i = easyfind(l, 5);
		std::cout << "Found in list: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in list test: " << e.what() << std::endl;
	}

	std::cout << std::endl << "--------- deque -----------" << std::endl;
	std::cout << "--------- jup -----------" << std::endl;

	std::deque<int>	d;

	i = 0;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	try
	{
		i = easyfind(d, 2);
		std::cout << "Found in deque: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in deque test: " << e.what() << std::endl;
	}

	std::cout << std::endl << "--------- no -----------" << std::endl;

	i = 0;
	try
	{
		i = easyfind(d, 5);
		std::cout << "Found in deque: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in deque test: " << e.what() << std::endl;
	}
	return (0);
}
