#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class	Bureaucrat;

class	Form
{
public:
	Form();
	Form(const Form &other);
	Form(const std::string name, const int gradeToSign, const int gradeToExec);
	~Form();

	Form	&operator=(const Form &other);

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExec(void) const;

	void		beSigned(const Bureaucrat &x);

	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif
