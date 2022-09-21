#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm", 25, 5), _target("Arthur Dent") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		Form::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->checkRequirements(executor) == true)
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return (true);
	}
	return (false);
}

std::string	PresidentialPardonForm::getTarget(void) const {return (this->_target);}
