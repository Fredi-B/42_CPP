#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &other);

	std::string	getName(void) const;
	int			getGrade(void) const;

	void	increment(void);
	void	decrement(void);

	void	signForm(Form &form);
	void	executeForm(const Form &form);

	class	GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b);

#endif
