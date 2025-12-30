#include "HumanA.hpp"

class HumanB
{
	std::string name;
	Weapon* weapon;
	public:
		HumanB(std::string name);
		~HumanB();
        void setWeapon(Weapon& weapon);
		void attack();
};