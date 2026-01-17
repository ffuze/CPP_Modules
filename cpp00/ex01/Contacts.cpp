/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:26:54 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts()
{

}

Contacts::~Contacts()
{

}

void Contacts::setName(const std::string& n)
{
    name = n;
}

void Contacts::setSurname(const std::string& s)
{
    surname = s;
}

void Contacts::setNickname(const std::string& n)
{
    nickname = n;
}

void Contacts::setPhone(const std::string& p)
{
    phone = p;
}

void Contacts::setSecret(const std::string& s)
{
    secret = s;
}

std::string Contacts::getName() const
{
    return (name);
}

std::string Contacts::getSurname() const
{
    return (surname);
}

std::string Contacts::getNickname() const
{
    return (nickname);
}

std::string Contacts::getPhone() const
{
    return (phone);
}

std::string Contacts::getSecret() const
{
    return (secret);
}
