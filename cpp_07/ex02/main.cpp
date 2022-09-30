#include "Array.hpp"
#include <iostream>

int	main(void)
{
	std::cout << std::endl << "----------int array---------" << std::endl;
	Array<>	a(2);
	try
	{
		a[0] = 3;
		a[1] = 2;
		std::cout << a[1] << std::endl;
		std::cout << "size of int array: " << a.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in int test: " << e.what() << std::endl;
	}


	std::cout << std::endl << "----------string array---------" << std::endl;
	Array<std::string>	b(3);
	try
	{
		b[0] = "hello";
		b[1] = "world";
		b[2] = "!";
		std::cout << b[2] << std::endl;
		std::cout << "size of string array: " << b.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in string test: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "----------char array---------" << std::endl;
	Array<char>	c1(3);
	try
	{
		c1[0] = 'a';
		c1[1] = 'b';
		c1[2] = 'c';
		std::cout << "char array: "<< c1[2] << std::endl;
		std::cout << "size of char array: " << c1.size() << std::endl;
		std::cout << std::endl << "----------copy---------" << std::endl;
		Array<char> c2 = c1;
		std::cout << "copy array: " << c2[2] << std::endl;
		std::cout << "size of char array copy: " << c2.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in char test: " << e.what() << std::endl;
	}
	
	return (0);
}
