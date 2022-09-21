#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequestForm", 72, 45), _target("mountain") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		Form::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->checkRequirements(executor) == true)
	{
		std::cout << "ddddrrrrrr" << std::endl;
		if (arc4random() % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed to robotomize " << this->getTarget() << std::endl;
		return (true);
	}
	return (false);
}

std::string	RobotomyRequestForm::getTarget(void) const {return (this->_target);}
