/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

class Contacts
{
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string phone;
		std::string secret;
	public:
		Contacts();
		~Contacts();
		void setName(const std::string& n);
		void setSurname(const std::string& s);
		void setNickname(const std::string& n);
		void setPhone(const std::string& p);
		void setSecret(const std::string& s);
		std::string getName() const;
		std::string getSurname() const;
		std::string getNickname() const;
		std::string getPhone() const;
		std::string getSecret() const;
};
