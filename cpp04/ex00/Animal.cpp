/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:07:05 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 16:57:50 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Typeless animal was just created" << std::endl;
	type = "typeless";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal " << type << " was just created" << std::endl;
}

Animal::~Animal()
{
	if (this->type.empty())
		std::cout << "Typeless animal was just annihilated" << std::endl;
	else
		std::cout << "Animal " << this->type << " was just annihilated" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

Animal::Animal(const Animal& other)
{
	Animal::operator=(other);
	std::cout << "Animal " << this->type << " copy constructor just created" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "uuuuuuuhh" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::setType(std::string type)
{
	this->type = type;
}
