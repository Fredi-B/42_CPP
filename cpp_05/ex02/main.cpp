#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	b("bini", 40);
	Form		f("formi", 40, 36);
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	b.signForm(f);
	return (0);
}
