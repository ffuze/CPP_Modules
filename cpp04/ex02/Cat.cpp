/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:26:54 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 16:58:43 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "A cat was just created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A cat was just annihilated :(" << std::endl;
	delete (brain);
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		Animal::operator=(obj);
		*this->brain = *(obj.brain);
	}
	return (*this);
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->brain = new Brain(*(other.brain));
	std::cout << this->type << " copy constructor was just created" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow ni-" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->brain;
}
