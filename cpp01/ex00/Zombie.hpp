#include <iostream>
#include <iomanip>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string _name);
		~Zombie();
		void    announce(void);
};
	
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);