#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { }

PhoneBook::~PhoneBook(void) { }

bool	PhoneBook::add_contact(int index)
{
	std::string	first_name = "";
	std::string	last_name = "";
	std::string	nickname = "";
	std::string	phone_number = "";
	std::string	darkest_secret = "";

	while (first_name == "" && !std::cin.eof())
		first_name = this->get_contact_details("first name");
	while (last_name == "" && !std::cin.eof())
		last_name = this->get_contact_details("last name");
	while (nickname == "" && !std::cin.eof())
		nickname = this->get_contact_details("nickname");
	while (phone_number == "" && !std::cin.eof())
		phone_number = this->get_contact_details("phone number");
	while (darkest_secret == "" && !std::cin.eof())
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

	if (this->contacts[0].get_field("first_name") == "")
	{
		std::cout << "Phonebook empty" << std::endl;
		return ;
	}
	i = 0;
	while (i < 8)
	{
		if (this->contacts[i].get_field("first_name") != "")
		{
			std::cout.width(10);
			std::cout << std::right << i + 1 << "|";
			std::cout.width(10);
			if (this->contacts[i].get_field("first_name").length() <= 10)
				std::cout << std::right << this->contacts[i].get_field("first_name") << "|";
			else
				std::cout << std::right << this->truncate_contact_detail(contacts[i].get_field("first_name")) << "|";
			std::cout.width(10);
			if (this->contacts[i].get_field("last_name").length() <= 10)
				std::cout << std::right << this->contacts[i].get_field("last_name") << "|";
			else
				std::cout << std::right << this->truncate_contact_detail(contacts[i].get_field("last_name")) << "|";
			std::cout.width(10);
			if (this->contacts[i].get_field("nickname").length() <= 10)
				std::cout << std::right << this->contacts[i].get_field("nickname") << std::endl;
			else
				std::cout << std::right << this->truncate_contact_detail(contacts[i].get_field("nickname")) << std::endl;
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

void	PhoneBook::search_contact(void)
{
	std::string	index_to_search = "";

	if (this->contacts[0].get_field("first_name") == "")
		return ;
	while ((index_to_search[0] < '1' || index_to_search[0] > '8' || index_to_search == "" || index_to_search.length() > 1) && !std::cin.eof())
		index_to_search = this->get_index();
	if ((this->contacts[index_to_search[0] - '1'].get_field("first_name") == ""))
	{
		std::cout << "Index not valid" << std::endl;
		return ;
	}
	if (!std::cin.eof())
	{
		std::cout.width(16);
		std::cout << std::left << "First name: " << this->contacts[index_to_search[0] - '1'].get_field("first_name") << std::endl;
		std::cout.width(16);
		std::cout << std::left << "Last name: " << this->contacts[index_to_search[0] - '1'].get_field("last_name") << std::endl;
		std::cout.width(16);
		std::cout << std::left << "Nickname: " << this->contacts[index_to_search[0] - '1'].get_field("nickname") << std::endl;
		std::cout.width(16);
		std::cout << std::left << "Phone number: " << this->contacts[index_to_search[0] - '1'].get_field("phone_number") << std::endl;
		std::cout.width(16);
		std::cout << std::left << "Darkest secret: " << this->contacts[index_to_search[0] - '1'].get_field("darkest_secret") << std::endl;
	}
}

std::string PhoneBook::get_index(void)
{
	std::string	index_to_search;

	std::cout << "Enter index:" << std::endl;
	std::getline(std::cin, index_to_search);
	if ((index_to_search[0] < '0' || index_to_search[0] > '9' || index_to_search == "" || index_to_search.length() > 1) && !std::cin.eof())
		std::cout << "Hint: enter a digit" << std::endl;
	return (index_to_search);
}
