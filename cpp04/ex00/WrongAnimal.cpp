/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:57:45 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 16:58:43 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Typeless WrongAnimal was just created" << std::endl;
	type = "typeless";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal " << type << " was just created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	if (this->type.empty())
		std::cout << "Typeless WrongAnimal was just annihilated" << std::endl;
	else
		std::cout << "WrongAnimal " << this->type << " was just annihilated" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	WrongAnimal::operator=(other);
	std::cout << "WrongAnimal " << this->type << " copy constructor just created" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "uuuuuuuhh wrong" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}
