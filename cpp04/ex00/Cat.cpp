/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:46:26 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:59 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "A cat was just created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A cat was just annihilated :(" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	return (*this);
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << this->type << " copy constructor was just created" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow ni-" << std::endl;
}
