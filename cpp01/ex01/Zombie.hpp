#include <iostream>
#include <iomanip>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		void    announce(void);
		void	nameZombie(std::string name);
};
	
Zombie*	zombieHorde(int N, std::string name);