#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int			index;

	index = 0;

	std::cout << "Welcome" << std::endl;
	std::cout << "You can ADD, SEARCH or EXIT" << std::endl;
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
			phonebook.search_contact();
		}
		else if (input == "EXIT")
			break ;
		std::cout << "\nYou can ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "\n#####   PHONEBOOK CLOSED  #####" << std::endl;
	std::cout << "##### ALL CONTACTS ERASED #####" << std::endl;
	return (0);
}
