#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << std::endl << "-------shrubbery test--------" << std::endl;
	Bureaucrat	b("bini", 137);
	ShrubberyCreationForm	f("formi");
	b.signForm(f);
	b.executeForm(f);

	return (0);
}
