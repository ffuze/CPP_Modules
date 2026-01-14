#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int x = 50;
	Animal* animals[x];
	for (int i = 0; i < x / 2; i++)
	{
		animals[i] = new Dog();
		animals[i]->makeSound();
		std::cout << "dog assignment index at: " << i << std::endl;
	}
	for (int i = x / 2 - 1; i < x ; i++)
	{
		animals[i] = new Cat();
		animals[i]->makeSound();
		std::cout << "cat assignment index at: " << i << std::endl;
	}
	for (int i = 0; i < x; i++)
	{
		delete[] animals[i];
		std::cout << "deletion index at: " << i << std::endl;
	}
	return 0;
}