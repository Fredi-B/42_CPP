#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:

		Contact(void);
		~Contact(void);

		void		set_field(std::string field, std::string input);
		std::string	get_field(std::string field);

};

#endif