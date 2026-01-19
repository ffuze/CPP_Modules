/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:26:54 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/19 16:54:07 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void testBrainIdeas()
{
	std::cout << "\n========== Brain ideas ==========\n" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->setIdea("Sell weed");
	dog1->getBrain()->setIdea("Dominate the hood");
	dog1->getBrain()->setIdea("Order KFC");
	std::cout << "\nDog1's ideas:" << std::endl;
	std::string* ideas = dog1->getBrain()->getIdeas();
	for (int i = 0; i < 5; i++)
	{
		if (!ideas[i].empty())
			std::cout << "  Idea " << i << ": " << ideas[i] << std::endl;
	}
	Dog dog2(*dog1);
	std::cout << "\nDog2 ideas" << std::endl;
	ideas = dog2.getBrain()->getIdeas();
	for (int i = 0; i < 5; i++)
	{
		if (!ideas[i].empty())
			std::cout << "  Idea " << i << ": " << ideas[i] << std::endl;
	}
	dog2.getBrain()->setIdea("Release a new album");
	std::cout << "Dog1 ideas:" << std::endl;
	ideas = dog1->getBrain()->getIdeas();
	for (int i = 0; i < 5; i++)
	{
		if (!ideas[i].empty())
			std::cout << "  Idea " << i << ": " << ideas[i] << std::endl;
	}
	std::cout << "Dog2 ideas:" << std::endl;
	ideas = dog2.getBrain()->getIdeas();
	for (int i = 0; i < 5; i++)
	{
		if (!ideas[i].empty())
			std::cout << "  Idea " << i << ": " << ideas[i] << std::endl;
	}
	std::cout << "\n--- Testing Cat ---" << std::endl;
	Cat* cat1 = new Cat();
	cat1->getBrain()->setIdea("Knock things off table");
	cat1->getBrain()->setIdea("Sleep 20 hours");
	std::cout << "\nCat1's ideas:" << std::endl;
	ideas = cat1->getBrain()->getIdeas();
	for (int i = 0; i < 5; i++)
	{
		if (!ideas[i].empty())
			std::cout << "  Idea " << i << ": " << ideas[i] << std::endl;
	}
	delete dog1;
	delete cat1;
}

int main()
{
	testBrainIdeas();
	std::cout << "\n========== Obj creation and deletion ==========\n" << std::endl;
	int x = 50;
	Animal* animals[x];
	for (int i = 0; i < x / 2; i++)
	{
		std::cout << std::endl;
		animals[i] = new Dog();
		animals[i]->makeSound();
		std::cout << "dog assignment index at: " << i << std::endl;
	}
	std::cout << std::endl << "---------------------------------" << std::endl;
	for (int i = x / 2; i < x ; i++)
	{
		std::cout << std::endl;
		animals[i] = new Cat();
		animals[i]->makeSound();
		std::cout << "cat assignment index at: " << i << std::endl;
	}
	std::cout << std::endl << "---------------------------------" << std::endl;
	for (int i = 0; i < x; i++)
	{
		std::cout << std::endl;
		delete animals[i];
		std::cout << "deletion index at: " << i << std::endl;
	}
	return 0;
}
