#include "PhoneBook.hpp"

static int	get_contacts_length(PhoneBook pb)
{
	int	count;
	count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (pb.contacts[i].name.empty())
			break;
		count++;
	}
	return (count);
}

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
			int	l;
			bool not_valid = false;
			info = "";
			l = get_contacts_length(phonebook);
			if (l >= 8)
			{
				std::cout << "Contact list is full. Delete one contact" << std::endl;
				continue;
			}
			std::cout << "ADD command selected. Insert the new details:" << std::endl;
			std::cout << "Name: ";
			std::cin >> info;
			not_valid = false;
			while (!not_valid)
			{
				if (info.find_first_of(' ') == std::string::npos)
					not_valid = true;
				else
					std::cin >> info;
			}
			new_contact.name = info;
			std::cout << "Surname: ";
			std::cin >> info;
			not_valid = false;
			while (!not_valid)
			{
				if (info.find_first_of(' ') == std::string::npos)
					not_valid = true;
				else
					std::cin >> info;
			}
			new_contact.surname = info;
			std::cout << "Nickname: ";
			std::cin >> info;
			not_valid = false;
			while (!not_valid)
			{
				if (info.find_first_of(' ') == std::string::npos)
					not_valid = true;
				else
					std::cin >> info;
			}
			new_contact.nickname = info;
			std::cout << "Phone: ";
			std::cin >> info;
			not_valid = false;
			while (!not_valid)
			{
				if (info.find_first_of(' ') == std::string::npos)
					not_valid = true;
				else
					std::cin >> info;
			}
			new_contact.phone = info;
			std::cout << "Secret: ";
			std::cin >> info;
			not_valid = false;
			while (!not_valid)
			{
				if (info.find_first_of(' ') == std::string::npos)
					not_valid = true;
				else
					std::cin >> info;
			}
			new_contact.secret = info;
			// if (new_contact.name.empty() || new_contact.surname.empty()
			// || new_contact.nickname.empty() || new_contact.phone.empty()
			// || new_contact.secret.empty())
			// {
			// 	std::cout << "Missing value found. Stop" << std::endl;
			// 	continue;
			// }
			phonebook.contacts[l] = new_contact;
		}
		else if (option == "SEARCH")
		{
			// DA FIXARE:
			// -- 1 --
			// Secret: a        a
			// Info 5: a
			// Please select between ADD, SEARCH and EXIT
			// Please select between ADD, SEARCH and EXIT
			// -- 2 --
			// Please select between ADD, SEARCH and EXIT
            //                      EXIT
			// Please select between ADD, SEARCH and EXIT
            //                ADD
			for (int i = 1; i <= get_contacts_length(phonebook); i++)
			{
				// create an opening line for the table
				std::string name = phonebook.contacts[i - 1].name;
				std::string surname = phonebook.contacts[i - 1].surname;
				std::string nickname = phonebook.contacts[i - 1].nickname;
				if (name.length() > 10)
					name = name.substr(0, 9) + '.';
				if (surname.length() > 10)
					surname = surname.substr(0, 9) + '.';
				if (nickname.length() > 10)
					nickname = nickname.substr(0, 9) + '.';
				std::cout << std::setw(10) << i << '|'
							<< std::setw(10) << name << '|'
							<< std::setw(10) << surname << '|'
							<< std::setw(10) << nickname 
							<< std::endl;
				
			}
		}
		else if (option == "EXIT")
			break;
		else
			continue;
	}
}