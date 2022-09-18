#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class	Form
{
public:
	Form();
	Form(const Form &oteher);
	Form(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExec);
	~Form();

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExec(void) const;

	void		beSigned(Bureaucrat x);

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif
