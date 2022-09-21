#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	// std::cout << std::endl << "-------shrubbery test--------" << std::endl;
	// Bureaucrat	bf("bini", 137);
	// ShrubberyCreationForm	f("formi");
	// bf.signForm(f);
	// bf.executeForm(f);

	std::cout << std::endl << "-------robotomy test--------" << std::endl;
	Bureaucrat	br("bini", 40);
	RobotomyRequestForm	r("robbi");
	br.signForm(r);
	br.executeForm(r);
	return (0);
}
