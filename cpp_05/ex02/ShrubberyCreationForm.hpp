#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

	bool		execute(const Bureaucrat &executor) const;
	std::string	getTarget(void) const;
private:
	std::string	_target;
};

#endif
