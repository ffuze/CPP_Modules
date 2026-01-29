/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:27:27 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/18 17:10:47 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl << "=== getType ===" << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;

    std::cout << std::endl << "=== makeSound ===" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl << "=== Copy constructor ===" << std::endl;
    Cat originalCat;
    Cat copyCat(originalCat);
    std::cout << "Original type: " << originalCat.getType() << std::endl;
    std::cout << "Copy type: " << copyCat.getType() << std::endl;

    std::cout << std::endl << "=== Assignment operator ===" << std::endl;
    Dog dog1;
    Dog dog2;
    dog2 = dog1;
    std::cout << "dog2 type after assignment: " << dog2.getType() << std::endl;

    std::cout << std::endl << "=== Destructors ===" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "=== WrongAnimals ===" << std::endl;
    const WrongAnimal* stuped = new WrongCat();
    std::cout << "stuped type: " << stuped->getType() << std::endl;
    stuped->makeSound();

    delete stuped;
    return (0);
}
