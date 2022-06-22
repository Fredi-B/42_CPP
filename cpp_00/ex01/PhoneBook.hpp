#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:

		Contact	contacts[8];

		std::string	get_contact_details(std::string field);
		std::string	truncate_contact_detail(std::string contact_detail);
		
	public:

		PhoneBook(void);
		~PhoneBook(void);

		bool	add_contact(int index);
		void	display_contacts(void);
};

#endif