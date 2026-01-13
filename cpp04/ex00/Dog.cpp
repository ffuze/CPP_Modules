#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "A dog was just created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "A dog was just annihilated :(" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
        Animal::operator=(obj);
    return (*this);
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << this->type << " copy constructor was just created" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "What the dawg doin" << std::endl;
}