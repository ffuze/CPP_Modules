#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	Contacts contact1;
	Contacts contact2;
	std::string option;
	
	contact1.name = "Alex";
	contact1.surname = "Degl\'innocenti";
	contact1.phone = "123";
	contact1.nickname = "Alek";
	contact1.secret = "Secret";
	contact2.name = "Ilyas";
	contact2.surname = "Mahjoubi";
	contact2.phone = "987";
	contact2.nickname = "Khallawi";
	contact2.secret = "Zemen";
	phonebook.contacts[0] = contact1;
	phonebook.contacts[1] = contact2;
	std::cout << "User joined your channel. ";
	while (true)
	{
		std::cout << "Please select between ADD, SEARCH and EXIT" << std::endl;
		std::cin >> option;
		if (option == "ADD")
		{
			Contacts new_contact = {};
			std::string info;
			int i;

			info = "";
			i = 0;
			std::cout << "ADD command selected. Insert the new details:" << std::endl;
			std::cout << "Name: ";
			std::cin >> info;
			new_contact.name = info;
			std::cout << "Info 1: " << new_contact.name << std::endl;
			std::cout << "Surname: ";
			std::cin >> info;
			new_contact.surname = info;
			std::cout << "Info 2: " << info << std::endl;
			std::cout << "Nickname: ";
			std::cin >> info;
			new_contact.nickname = info;
			std::cout << "Info 3: " << info << std::endl;
			std::cout << "Phone: ";
			std::cin >> info;
			new_contact.phone = info;
			std::cout << "Info 4: " << info << std::endl;
			std::cout << "Secret: ";
			std::cin >> info;
			new_contact.secret = info;
			std::cout << "Info 5: " << info << std::endl;
			if (new_contact.name.empty() || new_contact.surname.empty()
			|| new_contact.nickname.empty() || new_contact.phone.empty()
			|| new_contact.secret.empty())
			{
				std::cout << "Missing value found. Stop" << std::endl;
				continue;
			}
			// while (phonebook.contacts[i] != '\0')
		}
		else if (option == "SEARCH")
		{
			
		}
		else if (option == "EXIT")
		{
			std::cout << "Exiting" << std::endl;
			break;
		}
		else
			std::cout << "Incorrect option" << std::endl;
	}
}