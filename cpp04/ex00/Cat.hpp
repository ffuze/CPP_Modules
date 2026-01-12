#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		std::string _type;
	public:
		Cat(std::string type);
		~Cat();
		Cat(const Cat& other);
		Cat operator=(const Cat& other);
		void makeSound();
};

#endif