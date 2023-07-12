#include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	int			index;
	Phonebook	phonebook;
	std::string	id;

	index = 0;
	id = "";
	while (1)
	{
		std::cout << "Enter a command -> ";
		std::getline(std::cin, input);
		if (input == "SEARCH")
		{
			std::cout << "|   Index  |First Name| LastName | NickName |" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			phonebook.printList();
			std::cout << "Enter id of contact -> ";
			std::getline(std::cin, id);
			if (id == "")
			{
				std::cout << "Id can not be empty!" << std::endl;
				continue;
			}
			else if (isdigit(id[0]) == false)
			{
				std::cout << "Id must be a number!" << std::endl;
				continue;
			}
			else if (std::stoi(id) < 1 || std::stoi(id) > 8)
			{
				std::cout << "Id must be betweeen 1 and 8!" << std::endl;
				continue;
			}
			phonebook.printContact(std::stoi(id));
		}
		else if (input == "ADD")
		{
			Contact 	contact;
			std::string	firstName;
			std::string	lastName;
			std::string	nickName;
			std::string	phoneNumber;
			std::string	darkestSecret;
			std::cout << "Enter first name -> ";
			std::getline(std::cin, firstName);
			if (firstName == "\n")
			{
				std::cout << "First name can not be empty!" << std::endl;
				continue ;
			}
			contact.setFirstname(firstName);
			std::cout << "Enter last name -> ";
			std::getline(std::cin, lastName);
			if (lastName == "")
			{
				std::cout << "Last name can not be empty!" << std::endl;
				continue ;
			}
			contact.setLastname(lastName);
			std::cout << "Enter nick name -> ";
			std::getline(std::cin, nickName);
			if (nickName == "")
			{
				std::cout << "Nick name can not be empty!" << std::endl;
				continue ;
			}
			contact.setNickname(nickName);
			std::cout << "Enter phone number -> ";
			std::getline(std::cin, phoneNumber);
			if (phoneNumber == "")
			{
				std::cout << "Phone number can not be empty!" << std::endl;
				continue ;
			}
			contact.setPhoneNumber(phoneNumber);
			std::cout << "Enter darkest secret -> ";
			std::getline(std::cin, darkestSecret);
			if (darkestSecret == "")
			{
				std::cout << "Darkest secret can not be empty!" << std::endl;
				continue ;
			}
			contact.setDarkestsecret(darkestSecret);
			phonebook.addContact(contact, index);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (input == "EXIT")
			return (0);
	}
	return (0);
}