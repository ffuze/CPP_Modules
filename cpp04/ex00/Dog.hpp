#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : virtual public Animal
{
	private:
		std::string type;
	public:
		Dog(std::string type);
        Dog();
        Dog(const Dog& other);
        Dog operator=(const Dog& other);
        void makeSound();
};

#endif