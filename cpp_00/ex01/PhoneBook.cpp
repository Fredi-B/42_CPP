#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

bool	PhoneBook::add_contact(int index)
{
	std::string	first_name = "";
	std::string	last_name = "";
	std::string	nickname = "";
	std::string	phone_number = "";
	std::string	darkest_secret = "";

	while (first_name == "")
		first_name = this->get_contact_details("first name");
	while (last_name == "")
		last_name = this->get_contact_details("last name");
	while (nickname == "")
		nickname = this->get_contact_details("nickname");
	while (phone_number == "")
		phone_number = this->get_contact_details("phone number");
	while (darkest_secret == "")
		darkest_secret = this->get_contact_details("darkest secret");
	PhoneBook::contacts[index].set_field("first_name", first_name);
	PhoneBook::contacts[index].set_field("last_name", last_name);
	PhoneBook::contacts[index].set_field("nickname", nickname);
	PhoneBook::contacts[index].set_field("phone_number", phone_number);
	PhoneBook::contacts[index].set_field("darkest_secret", darkest_secret);
	std::cout << "Contact added" << std::endl;
	return (true);
}

std::string	PhoneBook::get_contact_details(std::string field)
{
	std::string	input;

	std::cout << "Enter " << field << ":" << std::endl;
	std::getline(std::cin, input);
	if (input == "")
		std::cout << "Hint: A contact can't have empty fields" << std::endl;
	return (input);
}

void	PhoneBook::display_contacts(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (this->contacts[i].get_field("first_name") != "")
		{
			std::cout.width(10);
			std::cout << std::right << i + 1<< "|";
			std::cout.width(10);
			if (this->contacts[i].get_field("first_name").length() <= 10)
				std::cout << std::right << this->contacts[i].get_field("first_name") << "|";
			else
				std::cout << std::right << this->truncate_contact_detail(contacts[i].get_field("first_name")) << "|";
			/* die beiden couts machen wie oben */
			std::cout.width(10);
			std::cout << std::right << this->contacts[i].get_field("last_name") << "|";
			std::cout.width(10);
			std::cout << std::right << this->contacts[i].get_field("nickname") << "|" << std::endl;
		}
		i++;
	}
}

std::string	PhoneBook::truncate_contact_detail(std::string contact_detail)
{
	contact_detail.erase(9, 1000);
	contact_detail.replace(9, 1, ".");
	return (contact_detail);
}

