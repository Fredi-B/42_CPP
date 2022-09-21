#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) {*this = other;}
Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

static Form	*makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static Form	*makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	Form	*(*func[3])(std::string target) = {&makeShrubbery, \
											&makeRobotomy, \
											&makePresidential};
	std::string	form_types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (form_types[i] == name)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return ((*func[i])(target));
		}
	}
	std::cout << "Intern couldn't create because " << name << " is made up" << std::endl;
	return (NULL);
}
