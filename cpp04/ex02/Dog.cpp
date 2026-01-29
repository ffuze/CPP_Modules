/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:27:43 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 16:58:43 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "A dog was just created" << std::endl;
    brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "A dog was just annihilated :(" << std::endl;
    delete (brain);
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        *this->brain = *(obj.brain);
    }
    return (*this);
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    std::cout << this->type << " copy constructor was just created" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "What the dawg doin" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}
