#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	b("bini", 5);
	Intern		someRandomIntern;

	std::cout << std::endl << "-----------robotomy test---------" << std::endl;
	Form		*rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	b.signForm(*rrf);
	b.executeForm(*rrf);

	std::cout << std::endl  << "-----------shrubbery test---------" << std::endl;
	Form		*scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Hill");
	b.signForm(*scf);
	b.executeForm(*scf);

	std::cout << std::endl  << "-----------presidential test---------" << std::endl;
	Form		*ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Arty");
	b.signForm(*ppf);
	b.executeForm(*ppf);

	std::cout << std::endl  << "-----------random form test---------" << std::endl;
	Form		*rff;
	rff = someRandomIntern.makeForm("random form", "Arty");
	return (0);
}
