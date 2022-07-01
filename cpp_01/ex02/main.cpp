#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string	var = "HI THIS IS BRAIN";
	std::string	*stringPTR = &var;
	std::string &stringREF = var;

	std::cout << std::endl;

	std::cout << std::setw(27);
	std::cout << std::left << "address of the string: ";
	std::cout << &var << std::endl;
	std::cout << "address held by stringPTR: "
			<< stringPTR << std::endl;
	std::cout << "address held by stringREF: "
			<< &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(31);
	std::cout << std::left << "value of the string: ";
	std::cout << var << std::endl;
	std::cout << "value pointed to by stringPTR: "
			<< *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: "
			<< stringREF << std::endl;

	std::cout << std::endl;
	return (0);
}
