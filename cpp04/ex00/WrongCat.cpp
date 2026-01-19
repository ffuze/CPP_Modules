/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:58:06 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 17:09:55 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "A WrongCat was just created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat was just annihilated :(" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		WrongAnimal::operator=(obj);
	return (*this);
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << this->type << " copy constructor was just created" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "butter cat, the cat with the butter" << std::endl;
}
