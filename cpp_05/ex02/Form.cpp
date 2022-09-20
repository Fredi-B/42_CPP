#include "Form.hpp"

Form::Form() : _name("XY"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const Form &other)
: _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	*this = other;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return (*this);
}

std::string	Form::getName(void) const	{ return (this->_name); }
bool		Form::getIsSigned(void) const { return (this->_isSigned); }
int			Form::getGradeToSign(void) const { return (this->_gradeToSign); }
int			Form::getGradeToExec(void) const { return (this->_gradeToExec); }

void	Form::beSigned(const Bureaucrat &x)
{
	if (x.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

bool	Form::checkRequirements(const Bureaucrat &executor) const
{
	try
	{
		if (this->getIsSigned() == false)
			throw Form::FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExec())
			throw Form::GradeTooLowException();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << executor << " couldn't execute " 
		<< this->getName() << " because " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream	&operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << ": grade to sign: " << f.getGradeToSign()
	<< ", grade to execute: " << f.getGradeToExec()
	<< ", signed: " << f.getIsSigned();
	return (o);
}
