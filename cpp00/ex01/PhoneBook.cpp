/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int	get_contacts_length(PhoneBook pb)
{
	int	count;
	count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (pb.contacts[i].getName().empty())
			break;
		count++;
	}
	return (count);
}

static void	parse_input(bool& not_valid, std::string& input, std::string message, int count)
{
	not_valid = input.empty()
				|| input[0] == ' '
				|| std::count(input.begin(), input.end(), ' ') > count
				|| input.find("  ") != std::string::npos;
	while (not_valid)
	{
		std::cout << message;
		if (!std::getline(std::cin, input))
			exit(0);
		not_valid = input.empty()
					|| input[0] == ' '
					|| std::count(input.begin(), input.end(), ' ') > count
					|| input.find("  ") != std::string::npos;
	}
}

int main(void)
{
	PhoneBook phonebook;
	Contacts contact1;
	Contacts contact2;
	std::string option;
	
	contact1.setName("Name1");
	contact1.setSurname("Surname1");
	contact1.setPhone("123");
	contact1.setNickname("Nick1");
	contact1.setSecret("Secret1");
	contact2.setName("Name2");
	contact2.setSurname("Surname2");
	contact2.setPhone("456");
	contact2.setNickname("Nick2");
	contact2.setSecret("Secret2");
	phonebook.contacts[0] = contact1;
	phonebook.contacts[1] = contact2;
	std::cout << "User joined your channel. ";
	while (true)
	{
		bool not_valid = false;
		std::cout << "Please select between ADD, SEARCH and EXIT" << std::endl;
		if (!std::getline(std::cin, option))
			break;
		parse_input(not_valid, option, "No spaces or empty fields are allowed: ", 0);
		if (option == "ADD")
		{
			Contacts new_contact;
			std::string info;
			int	l;
			info = "";
			l = get_contacts_length(phonebook);
			if (l >= 8)
			{
				std::cout << "Contact list is full." << std::endl;
				continue;
			}
			std::cout << "ADD command selected. Insert the new details:" << std::endl;
			std::cout << "Name: ";
			std::getline(std::cin, info);
			parse_input(not_valid, info, "Name (max 3 spaces allowed and no empty field): ", 3);
					   new_contact.setName(info);
			std::cout << "Surname: ";
			std::getline(std::cin, info);
			parse_input(not_valid, info, "Surname (max 3 spaces allowed and no empty field): ", 3);
					   new_contact.setSurname(info);
			std::cout << "Nickname: ";
			std::getline(std::cin, info);
			parse_input(not_valid, info, "Nickname (max 3 spaces allowed and no empty field): ", 3);
					   new_contact.setNickname(info);
			std::cout << "Phone: ";
			std::getline(std::cin, info);
			parse_input(not_valid, info, "Phone (max 1 space allowed and no empty field): ", 1);
					   new_contact.setPhone(info);
			std::cout << "Secret: ";
			std::getline(std::cin, info);
			parse_input(not_valid, info, "Secret (max 5 spaces allowed and no empty field): ", 5);
					   new_contact.setSecret(info);
			phonebook.contacts[l] = new_contact;
		}
		else if (option == "SEARCH")
		{
			for (int i = 1; i <= get_contacts_length(phonebook); i++)
			{
				std::string name = phonebook.contacts[i - 1].getName();
				std::string surname = phonebook.contacts[i - 1].getSurname();
				std::string nickname = phonebook.contacts[i - 1].getNickname();
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
