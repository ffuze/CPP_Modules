#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(std::string type);
        ~Animal();
        Animal(const Animal& other);
        Animal operator=(const Animal& other);
        void makeSound();
        std::string getType() const;
        void setType(std::string type);
};

#endif