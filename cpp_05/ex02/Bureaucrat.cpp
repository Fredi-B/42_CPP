#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Peter"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName(void) const {return (this->_name);}
int			Bureaucrat::getGrade(void) const {return (this->_grade);}

void	Bureaucrat::increment(void) 
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrement(void) 
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == true)
		std::cout << *this << " couldn't sign " << form << " because it's already signed" << std::endl;
	else
		try
		{
			form.beSigned(*this);
		}
		catch(const std::exception& e)
		{
			std::cerr <<  *this << " couldn't sign " << form << " because " << e.what() << std::endl;
		}
}

void	Bureaucrat::executeForm(const Form &form)
{
	if (form.execute(*this) == true)
		std::cout << *this << " executed " << form << std::endl;
	else
		std::cout << this->getName() << " can't execute " << form.getName() << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}
