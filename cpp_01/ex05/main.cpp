#include "Harl.hpp"

int	main(void)
{
	Harl	customer;

	customer.complain("DEBUG");
	customer.complain("INFO");
	customer.complain("WARNING");
	customer.complain("ERROR");
	customer.complain("test");
	return (0);
}