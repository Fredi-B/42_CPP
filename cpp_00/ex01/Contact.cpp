#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) { }

Contact::~Contact(void) { }

void	Contact::set_field(std::string field, std::string input)
{
	if (field == "first_name")
		Contact::first_name = input;
	else if (field == "last_name")
		Contact::last_name = input;
	else if (field == "nickname")
		Contact::nickname = input;
	else if (field == "phone_number")
		Contact::phone_number = input;
	else if (field == "darkest_secret")
		Contact::darkest_secret = input;
}

std::string	Contact::get_field(std::string field)
{
	if (field == "first_name")
		return (Contact::first_name);
	else if (field == "last_name")
		return (Contact::last_name);
	else if (field == "nickname")
		return (Contact::nickname);
	else if (field == "phone_number")
		return (Contact::phone_number);
	else if (field == "darkest_secret")
		return (Contact::darkest_secret);
	return ("Error in Contact::get_field(std::string field): input is not a field");
}
