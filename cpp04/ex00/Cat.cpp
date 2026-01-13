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