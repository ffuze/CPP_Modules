#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap
{
	protected:
		std::string _name;
		int _health;
		int _energy;
		int _attack;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
