#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << std::endl << "-------shrubbery test--------" << std::endl;
		Bureaucrat				bf("bini", 137);
		ShrubberyCreationForm	f("formi");
		bf.signForm(f);
		bf.executeForm(f);

		std::cout << std::endl << "-------robotomy test--------" << std::endl;
		Bureaucrat			br("vanni", 40);
		RobotomyRequestForm	r("robbi");
		br.signForm(r);
		br.executeForm(r);

		std::cout << std::endl << "-------presidential test--------" << std::endl;
		Bureaucrat				bp("pauli", 4);
		PresidentialPardonForm	p("arty");
		bp.signForm(p);
		bp.executeForm(p);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main(): " << e.what() << std::endl;
	}
	return (0);
}
