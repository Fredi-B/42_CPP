#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int			index;

	index = 0;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
		{
			if (phonebook.add_contact(index) == true)
				index++;
			if (index >= 8)
				index = 0;
		}
		else if (input == "SEARCH")
		{
			phonebook.display_contacts();
		}
		else if (input == "EXIT")
			break ;
		else
			std::cout << "You can ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
